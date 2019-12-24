#ifndef _SWAY_WEBCORE_BASE_TREENODEELEMENTUPDATEKIND_H
#define _SWAY_WEBCORE_BASE_TREENODEELEMENTUPDATEKIND_H

#include <sway/namespacemacros.h>
#include <sway/types.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(base)

enum class TreeNodeElementUpdateKind : u32_t {
	Insert,
	Delete
};

NAMESPACE_END(base)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_BASE_TREENODEELEMENTUPDATEKIND_H
