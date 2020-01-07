#ifndef _SWAY_WEBCORE_NODEVISITOR_H
#define _SWAY_WEBCORE_NODEVISITOR_H

#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

class TreeNodeElement;
class ITreeVisitor
	: public core::utilities::Visitor {

public:
	virtual ~ITreeVisitor() = default;

	virtual void visitOnEnter(TreeNodeElement * node) = 0;
	virtual void visitOnLeave(TreeNodeElement * node) = 0;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_NODEVISITOR_H
