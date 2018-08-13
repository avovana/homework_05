#pragma once
#include <memory>

#include "painter.h"

class AbstractModel;
class MyModel;

class AbstractView: public std::enable_shared_from_this<AbstractView> {
public:
	virtual void setModel(std::shared_ptr<AbstractModel>) = 0;
	virtual void drawElements() = 0;
};

class MyView : public AbstractView {
public:
	void setModel(std::shared_ptr<AbstractModel> model) override;
	void drawElements() override;

private:
	std::shared_ptr<AbstractModel> model;
	Painter painter;
};