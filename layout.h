#ifndef QTL_LAYOUT_H
#define QTL_LAYOUT_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>

#include <memory>
#include <tuple>

namespace qtl {


template<class Base, class Layout, class... Children>
class Container : public Base {
public:
    Container() {
        auto layout = std::make_unique<Layout>();
        auto children_smart = std::make_tuple(std::make_unique<Children>()...);

        children_ = std::apply([&layout](auto&&... smart) {
            auto dumb = std::make_tuple(smart.get()...);
            (layout->addWidget(smart.release()), ...);
            return dumb;
        }, children_smart);

        Base::setLayout(layout.release());
    }

    template<auto Id>
    auto child() {
        return std::get<Id>(children_);
    }

    template<auto Id1, auto Id2, auto... Rest>
    auto child() {
        return child<Id1>()->template child<Id2, Rest...>();
    }

private:
    std::tuple<Children*...> children_;
};

template<class... Children>
using HBox = Container<QWidget, QHBoxLayout, Children...>;

template<class... Children>
using VBox = Container<QWidget, QVBoxLayout, Children...>;


} // namespace qtl

#endif // QTL_LAYOUT_H
