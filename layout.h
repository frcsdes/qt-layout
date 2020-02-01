#ifndef QT_LAYOUT_LAYOUT_H
#define QT_LAYOUT_LAYOUT_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>

#include <memory>
#include <tuple>

namespace qtl {


template<class Parent, class Layout, class... Widgets>
auto layout() {
    auto parent = std::make_unique<Parent>();
    auto layout = std::make_unique<Layout>();

    auto widgets_smart = std::make_tuple(std::make_unique<Widgets>()...);
    auto widgets_dumb = std::apply([&layout](auto&... smart) {
        auto dumb = std::make_tuple(smart.get()...);
        (layout->addWidget(smart.release()), ...);
        return dumb;
    }, widgets_smart);

    parent->setLayout(layout.release());
    return std::make_pair(std::move(parent), widgets_dumb);
}

template<class... Widgets>
auto horizontal() {
    return layout<QWidget, QHBoxLayout, Widgets...>();
}

template<class... Widgets>
auto vertical() {
    return layout<QWidget, QVBoxLayout, Widgets...>();
}


} // namespace qtl

#endif // QT_LAYOUT_LAYOUT_H
