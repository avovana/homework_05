#pragma once

#include "graph_object.h"

#include <memory>
#include <vector>

class AbstractView;

class AbstractModel {
public:
	using ObjectsType = std::vector< std::shared_ptr<GraphObj> >;

	virtual void addElement(std::unique_ptr<GraphObj>) = 0;
	virtual void deleteLast() = 0;
	virtual void subscribe(AbstractView*) = 0;
	virtual void notify() = 0;
	virtual ~AbstractModel() {};
	virtual ObjectsType getObjects() = 0;
};

class MyModel : public AbstractModel {
public:
	void addElement(std::unique_ptr<GraphObj> obj) override;
	void deleteLast() override;
	void subscribe(AbstractView* view) override;
	void notify() override;
	ObjectsType getObjects() override;

	std::vector< AbstractView* > subs;
	ObjectsType objects;
};