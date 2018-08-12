#include "view.h"
#include "model.h"

void MyView::setModel(AbstractModel* model_) {
	model = model_;
	model->subscribe(this);
}

void MyView::drawElements() {

	for (auto& obj : model->getObjects()) {
		obj->drawBy(&painter);
	}
}