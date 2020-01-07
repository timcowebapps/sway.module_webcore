#ifndef _SWAY_WEBCORE_TREEUPDATER_H
#define _SWAY_WEBCORE_TREEUPDATER_H

#include <sway/webcore/treevisitor.h>
#include <sway/webcore/nodesynchronizer.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

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

	#pragma endregion

	#pragma region ITreeVisitor implementation

	virtual void visitOnEnter(TreeNodeElement * node);
	virtual void visitOnLeave(TreeNodeElement * node);

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

#endif // _SWAY_WEBCORE_TREEUPDATER_H
