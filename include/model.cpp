#include "model.h"
#include "view.h"

void MyModel::addElement(std::unique_ptr<GraphObj> obj) {
	objects.push_back(std::move(obj));
	notify();
}

void MyModel::deleteLast() {
	if (objects.empty())
		return;

	objects.pop_back();
	notify();
}

void MyModel::subscribe(std::weak_ptr<AbstractView> view) {
	subs.push_back(view);
}

void MyModel::notify() {
	for (auto ptr : subs)
		if(auto sub = ptr.lock())
			sub->drawElements();
}

MyModel::ObjectsType MyModel::getObjects() {
	return objects;
}