#include "TagMatchEngine.hpp"
#include "../../../helpers/TagKeeper.hpp"
#include <algorithm>
#include <string>

using namespace Desktop::Rule;

CTagMatchEngine::CTagMatchEngine(const std::string& tag) : m_tags({tag}) {
    ;
}

CTagMatchEngine::CTagMatchEngine(const std::vector<std::string>& tags) : m_tags(tags) {
    ;
}

bool CTagMatchEngine::match(const CTagKeeper& keeper) {
    return std::ranges::all_of(m_tags, [&keeper](const auto& tag) { return keeper.isTagged(tag); });
}
