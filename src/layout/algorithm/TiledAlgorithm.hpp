#pragma once

#include "../../helpers/math/Math.hpp"
#include "../../helpers/memory/Memory.hpp"

#include "ModeAlgorithm.hpp"

#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace Layout {

    class ITarget;
    class CAlgorithm;

    class ITiledAlgorithm : public IModeAlgorithm {
      public:
        virtual ~ITiledAlgorithm() = default;

        virtual SP<ITarget> getNextCandidate(SP<ITarget> old) = 0;

        // Optional runtime layout name. Useful for generic adapter classes where
        // typeid alone cannot identify the selected layout instance.
        virtual std::optional<std::string> layoutName() const {
            return std::nullopt;
        }

        // Optional extra per-window props for hyprctl clients output (e.g. master
        // status). Values are emitted as JSON literals, so booleans and numbers
        // must be given as e.g. "true" or "1", not quoted.
        virtual std::vector<std::pair<std::string, std::string>> additionalWindowProps(SP<ITarget>) {
            return {};
        }

      protected:
        ITiledAlgorithm() = default;

        friend class Layout::CAlgorithm;
    };
}
