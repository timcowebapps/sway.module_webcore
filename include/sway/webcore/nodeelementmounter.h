#ifndef _SWAY_WEBCORE_NODEELEMENTMOUNTER_H
#define _SWAY_WEBCORE_NODEELEMENTMOUNTER_H

#include <sway/webcore/nodesynchronizer.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

class NodeElementMounter
	: public core::containers::IHierarchyTraverser {
public:

#pragma region "Constructor / Destructor"

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	NodeElementMounter();

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~NodeElementMounter() = default;

#pragma endregion

#pragma region IHierarchyTraverser implementation

	virtual core::containers::TraversalAction_t visit(core::containers::HierarchyNode * node) override;

#pragma endregion

#pragma region General methods

	void forceUpdate();

#pragma endregion

private:
	NodeSynchronizer _synchronizer;
	PendingList _pendingUpdateNodes;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_NODEELEMENTMOUNTER_H
