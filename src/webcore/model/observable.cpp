#include <sway/webcore/model/observable.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(model)

Observable::Observable() {
	_observers = std::vector<view::IObserver *>();
}

Observable::~Observable() {
	_observers.clear();
}

void Observable::registerObserver(view::IObserver * observer) {
	_observers.push_back(observer);
}

void Observable::removeObserver(view::IObserver * observer) {
	view::ObserverArrayIterator_t iter = std::find(_observers.begin(), _observers.end(), observer);
	if (iter != _observers.end())
		_observers.erase(iter);
}

void Observable::notifyPropertyChanged() {
	for (view::IObserver * observer : _observers) {
		if (observer != nullptr)
			observer->onDataChanged();
	}
}

NAMESPACE_END(model)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
