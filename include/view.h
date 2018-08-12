#pragma once
#include "painter.h"

class AbstractModel;
class MyModel;

class AbstractView {
public:
	virtual void setModel(AbstractModel*) = 0;
	virtual void drawElements(MyModel* model) = 0;
};

class MyView : AbstractView {
public:
	void setModel(AbstractModel* model_) override;
	void drawElements(MyModel* model) override;

private:
	AbstractModel * model;
	Painter painter;
};