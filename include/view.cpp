#include "view.h"
#include "model.h"

void MyView::setModel(std::shared_ptr<AbstractModel> model_) {
	model = model_;
	model->subscribe(this);
}

void MyView::drawElements() {

	for (auto& obj : model->getObjects()) {
		obj->drawBy(&painter);
	}
}