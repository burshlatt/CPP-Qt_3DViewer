#ifndef OPENGL_H
#define OPENGL_H

#include <QTimer>
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include "qgifimage.h"
#include "../model/struct.h"

class OpenGL : public QOpenGLWidget {
  Q_OBJECT

    public:
        OpenGL(QWidget *parent = nullptr);
        ~OpenGL();

        void set_data(const Data &data) noexcept;
        void set_is_no_vertex(const bool &no) noexcept;
        void set_stipple(const bool &is_stipple) noexcept;
        void set_main_color(const QColor &color) noexcept;
        void set_line_color(const QColor &color) noexcept;
        void set_line_width(const double &width) noexcept;
        void set_vertex_color(const QColor &color) noexcept;
        void set_parallel(const bool &is_parallel) noexcept;
        void set_vertex_width(const double &width) noexcept;
        void set_is_circle_vertex(const bool &circle) noexcept;

        QImage GetFrame() noexcept;

        void Draw() noexcept;
        void Update() noexcept;
        void paintGL() override;
        void Perspective() noexcept;
        void initializeGL() override;
        void resizeGL(int w, int h) override;

    private:
        Data data_;

        bool is_stipple_;
        bool is_parallel_;
        bool is_no_vertex_;
        bool is_circle_vertex_;

        double line_width_;
        double vertex_width_;

        QColor main_color_;
        QColor line_color_;
        QColor vertex_color_;
};

#endif  // OPENGL_H
