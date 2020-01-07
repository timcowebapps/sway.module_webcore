#ifndef _SWAY_WEBCORE_REGIONCREATEINFO_H
#define _SWAY_WEBCORE_REGIONCREATEINFO_H

#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

struct RegionCreateInfo {
	std::string id; /*!< Уникальный идентификатор. */
	bool replace;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_REGIONCREATEINFO_H
