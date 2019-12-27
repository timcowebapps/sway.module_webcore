#ifndef _SWAY_WEBCORE_BASE_NODESYNCHRONIZER_H
#define _SWAY_WEBCORE_BASE_NODESYNCHRONIZER_H

#include <sway/webcore/base/dom/htmlbuilder.h>
#include <sway/webcore/base/pendingnode.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(base)

class NodeSynchronizer {
public:

	#pragma region Constructor / Destructor

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	NodeSynchronizer();

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~NodeSynchronizer();

	#pragma endregion // Constructor / Destructor

	void insertNode(PendingNode node);

	void removeNode(PendingNode node);

	void applyPendingUpdate(PendingNode node);

private:
	dom::HtmlBuilder * _htmlBuilder;
};

NAMESPACE_END(base)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_BASE_NODESYNCHRONIZER_H
