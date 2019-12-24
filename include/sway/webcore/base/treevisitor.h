#ifndef _SWAY_WEBCORE_BASE_NODEVISITOR_H
#define _SWAY_WEBCORE_BASE_NODEVISITOR_H

#include <sway/webcore/view/advanced/stackview.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(base)

class TreeNode;
class ITreeVisitor {
public:
	virtual ~ITreeVisitor() = default;
	virtual void visit(TreeNode * node) = 0;

	// virtual void visitOnEnter(TreeNode * node) = 0;
	// virtual void visitOnLeave(TreeNode * node) = 0;
};

NAMESPACE_END(base)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_BASE_NODEVISITOR_H
