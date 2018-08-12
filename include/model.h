#pragma once

#include "graph_object.h"

#include <memory>
#include <vector>

class AbstractView;

class AbstractModel {
public:
	virtual void addElement(std::unique_ptr<GraphObj>) = 0;
	virtual void deleteLast() = 0;
	virtual void subscribe(AbstractView*) = 0;
	virtual void notify() = 0;
	virtual ~AbstractModel() {};
	std::vector< std::unique_ptr<GraphObj> > objects;
};

class MyModel : public AbstractModel {
public:
	void addElement(std::unique_ptr<GraphObj> obj) override;
	void deleteLast() override;
	void subscribe(AbstractView* view) override;
	void notify() override;

	std::vector< AbstractView* > subs;
};