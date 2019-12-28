#ifndef _SWAY_WEBCORE_APPLICATION_H
#define _SWAY_WEBCORE_APPLICATION_H

#include <sway/core/containers/hierarchylistener.h>
#include <sway/webcore/base/dom/htmldocument.h>
#include <sway/webcore/base/dom/htmlelement.h>
#include <sway/webcore/base/treeupdater.h>
#include <sway/webcore/base/treenodeelement.h>
#include <sway/webcore/view/itemview.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

class Application
	: public core::containers::HierarchyListener {

public:

	#pragma region "Constructor / Destructor"

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

	virtual void onNodeAdded(const core::containers::HierarchyNodeIndex & nodeIndex);

	virtual void onNodeRemoved(core::containers::HierarchyNodePtr_t parent, core::containers::HierarchyNodePtr_t child);

	virtual void onNodeUpdated(const core::containers::HierarchyNodeIndex & nodeIndex);

	base::TreeNodeElement * getRoot();

	void start();

private:
	core::containers::Hierarchy * _tree;
	base::TreeNodeElement * _root;
	base::TreeUpdater * _treeUpdater;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_APPLICATION_H
