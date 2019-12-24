#ifndef _SWAY_WEBCORE_BASE_TREENODEELEMENT_H
#define _SWAY_WEBCORE_BASE_TREENODEELEMENT_H

#include <sway/webcore/eventtypes.h>
#include <sway/webcore/eventtarget.h>
#include <sway/webcore/eventhandler.h>

#include <sway/webcore/base/treenodeelementcreateinfo.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(base)

class TreeNode;
class TreeNodeElement {
public:

	#pragma region Static methods

	static void registerEmscriptenClass(lpcstr_t classname);

	#pragma endregion // Static methods

	#pragma region Constructor / Destructor

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	TreeNodeElement(const TreeNodeElementCreateInfo & createInfo);

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~TreeNodeElement() = default;

	#pragma endregion // Constructor / Destructor

	void addEvent(const std::string & targetId, const std::string & type, emscripten::val callback);

	void bindEvents();

	#pragma region Getters / Setters

	/*!
	 * \brief
	 *    Возвращает узел дерева.
	 */
	TreeNode * getTreeNode();

	/*!
	 * \brief
	 *    Устанавливает узел дерева.
	 * 
	 * \param[in] node
	 *    Узел дерева.
	 */
	void setTreeNode(TreeNode * node);

	/*!
	 * \brief
	 *    Возвращает имя тега.
	 */
	std::string getHtmlElementTagname() const;

	/*!
	 * \brief
	 *    Устанавливает имя тега.
	 * 
	 * \param[in] tagname
	 *    Имя тега.
	 */
	void setHtmlElementTagname(const std::string & tagname);

	/*!
	 * \brief
	 *    Возвращает уникальный идентификатор.
	 */
	std::string getHtmlElementId() const;

	/*!
	 * \brief
	 *    Устанавливает уникальный идентификатор.
	 * 
	 * \param[in] id
	 *    Уникальный идентификатор.
	 */
	void setHtmlElementId(const std::string & id);

	std::string getHtmlContent() const;

	void setHtmlContent(const std::string & content);

	bool hasVisibled() const;

	void setVisible(bool value);

	#pragma endregion // Getters / Setters

private:
	TreeNode * _treenode = nullptr; /*!< Узел дерева. */
	std::vector<EventHandler> _handlers;
	std::string _htmlElementTagname; /*!< Имя тега. */
	std::string _htmlElementId; /*!< Уникальный идентификатор. */
	std::string _htmlContent;
	bool _visibled;
};

NAMESPACE_END(base)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_BASE_TREENODEELEMENT_H
