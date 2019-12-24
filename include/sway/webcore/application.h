#ifndef _SWAY_WEBCORE_APPLICATION_H
#define _SWAY_WEBCORE_APPLICATION_H

#include <sway/webcore/dom/htmldocument.h>
#include <sway/webcore/dom/htmlelement.h>
#include <sway/core/containers/treelistener.h>
#include <sway/webcore/base/treeupdater.h>
#include <sway/webcore/base/treenode.h>
#include <sway/webcore/view/itemview.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

class Application
	: public core::containers::TreeListener {

public:

	#pragma region Constructor / Destructor

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	Application(const std::string & elementId);

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	~Application();

	#pragma endregion // Constructor / Destructor

	virtual void onNodeUpdated(core::containers::TreeNodePtr_t child);

	virtual void onNodeAdded(core::containers::TreeNodePtr_t parent, core::containers::TreeNodePtr_t child);

	virtual void onNodeRemoved(core::containers::TreeNodePtr_t parent, core::containers::TreeNodePtr_t child);

	base::TreeNode * getRoot();

	void start();

private:
	core::containers::Tree * _tree;
	base::TreeNode * _root;
	base::TreeUpdater * _treeUpdater;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_APPLICATION_H
