#include <sway/webcore/application.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

Application::Application(const std::string & elementId, mvc::view::ViewComponent * view)
	: _view(view) {

	dom::Element root = dom::Document::getElementById(elementId);
	if (root._val["children"]["length"].as<unsigned>())
		root.removeChild(dom::Element(root._val["firstChild"]));

	root.appendChild(_view->getElement());
}

Application::~Application() {
	SAFE_DELETE(_view);
}

void Application::start() {
	_view->render();
	
	_view->update();
}

NAMESPACE_END(webcore)
NAMESPACE_END(sway)
