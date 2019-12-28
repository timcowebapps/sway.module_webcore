#ifndef _SWAY_WEBCORE_BASE_TREEUPDATER_H
#define _SWAY_WEBCORE_BASE_TREEUPDATER_H

#include <sway/webcore/base/treevisitor.h>
#include <sway/webcore/base/nodesynchronizer.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(base)

class TreeNodeElement;
class TreeUpdater
	: public ITreeVisitor {
public:

	#pragma region "Constructor / Destructor"

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	TreeUpdater();

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~TreeUpdater();

	#pragma endregion // Constructor / Destructor

	#pragma region ITreeVisitor implementation

	virtual void visitOnEnter(TreeNodeElement * node);
	virtual void visitOnLeave(TreeNodeElement * node);

	#pragma endregion // ITreeVisitor implementation

	#pragma region General methods

	void forceUpdate();

	#pragma endregion // General methods

private:
	NodeSynchronizer _synchronizer;
	PendingList _pendingUpdateNodes;
};

NAMESPACE_END(base)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_BASE_TREEUPDATER_H
