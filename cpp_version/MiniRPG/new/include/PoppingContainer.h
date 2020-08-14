#pragma once

#include <memory>
#include <queue>

template<typename T>
class PoppingContainer {
public:
	PoppingContainer() : m_container() {};
	~PoppingContainer() {};

	void add(std::unique_ptr<T> ch) {
		m_container.push(std::move(ch));
	}
	std::unique_ptr<T> getNext() {
		auto result = std::move(m_container.front());
		m_container.pop();
		return std::move(result);
	}
	bool isEmpty() const {
		return m_container.empty();
	}

private:
	std::queue<std::unique_ptr<T>> m_container;
};