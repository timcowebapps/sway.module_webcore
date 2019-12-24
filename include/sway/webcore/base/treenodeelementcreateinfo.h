#ifndef _SWAY_WEBCORE_BASE_TREENODEELEMENTCREATEINFO_H
#define _SWAY_WEBCORE_BASE_TREENODEELEMENTCREATEINFO_H

#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(base)

struct TreeNodeElementCreateInfo {
	std::string tagname; /*!< Имя тега. */
	std::string id; /*!< Уникальный идентификатор. */
};

NAMESPACE_END(base)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_BASE_TREENODEELEMENTCREATEINFO_H
