#ifndef _SWAY_WEBCORE_NODEELEMENTUPDATER_H
#define _SWAY_WEBCORE_NODEELEMENTUPDATER_H

#include <sway/webcore/nodesynchronizer.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

class NodeElementUpdater
	: public core::containers::IHierarchyTraverser {
public:

#pragma region "Constructor / Destructor"

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	NodeElementUpdater();

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~NodeElementUpdater() = default;

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

#endif // _SWAY_WEBCORE_NODEELEMENTUPDATER_H
