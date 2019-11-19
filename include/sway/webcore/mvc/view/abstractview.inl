#include <sway/webcore/mvc/view/abstractview.h>
#include <sway/webcore/mvc/model/observable.h>
#include <type_traits>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(mvc)
NAMESPACE_BEGIN(view)

template<class OBSERVABLE_CLASS>
TAbstractView<OBSERVABLE_CLASS>::TAbstractView(const std::string & name)
	: TViewHierarchy<OBSERVABLE_CLASS>(name) {
	static_assert(std::is_base_of<model::Observable, OBSERVABLE_CLASS>::value, "type parameter of this class must derive from Observable");
}

template<class OBSERVABLE_CLASS>
TAbstractView<OBSERVABLE_CLASS>::~TAbstractView() {
	// Empty
}

template<class OBSERVABLE_CLASS>
void TAbstractView<OBSERVABLE_CLASS>::update() {
	// Empty
}

template<class OBSERVABLE_CLASS>
void TAbstractView<OBSERVABLE_CLASS>::setModel(OBSERVABLE_CLASS * model) {
	_model = model;
}

template<class OBSERVABLE_CLASS>
OBSERVABLE_CLASS * TAbstractView<OBSERVABLE_CLASS>::getModel() {
	return _model;
}

NAMESPACE_END(view)
NAMESPACE_END(mvc)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
