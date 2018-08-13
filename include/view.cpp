#include "view.h"
#include "model.h"

void MyView::setModel(std::shared_ptr<AbstractModel> model_) {
	model = model_;
	auto this_ptr = std::weak_ptr<AbstractView>(shared_from_this());
	model->subscribe(this_ptr);
}

void MyView::drawElements() {

	for (auto& obj : model->getObjects()) {
		obj->drawBy(&painter);
	}
}