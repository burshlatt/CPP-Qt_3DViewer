#ifndef VIEWER_H
#define VIEWER_H

#include <QColor>
#include <QColorDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QScreen>
#include <QSettings>
#include <QTimer>
#include <memory>

#include "../controller/controller.h"
#include "../model/struct.h"
#include "opengl.h"

namespace Ui {
class Viewer;
}

namespace s21 {
class Viewer : public QMainWindow {
  Q_OBJECT

 public:
  explicit Viewer(QWidget *parent = nullptr);
  ~Viewer();

  void SetFields() noexcept;
  void SetPosition() noexcept;
  void SetSettings() noexcept;
  void SetConnections() noexcept;

 public slots:
  void MoveXL() noexcept;
  void MoveXR() noexcept;
  void MoveYD() noexcept;
  void MoveYU() noexcept;
  void MoveZC() noexcept;
  void MoveZF() noexcept;
  void SaveGIF() noexcept;
  void OpenFile() noexcept;
  void ScaleMul() noexcept;
  void ScaleDiv() noexcept;
  void LineColor() noexcept;
  void MainColor() noexcept;
  void CreateGIF() noexcept;
  void VertexType() noexcept;
  void LWidthPlus() noexcept;
  void VWidthPlus() noexcept;
  void LWidthMinus() noexcept;
  void VWidthMinus() noexcept;
  void VertexColor() noexcept;
  void StippleType() noexcept;
  void SaveSettings() noexcept;
  void LoadSettings() noexcept;
  void ProjectionType() noexcept;
  void CreateScreenshot() noexcept;
  void RotateX(const int &value) noexcept;
  void RotateY(const int &value) noexcept;
  void RotateZ(const int &value) noexcept;

 private:
  Ui::Viewer *ui_;
  std::unique_ptr<Controller> controller_;

  int frame_count_;
  double l_width_, v_width_;
  int check_x_, check_y_, check_z_;

  QTimer *timer_;
  QGifImage *frame_;
  QString gif_name_;
  QSettings *settings_;
  QColor color_main_, color_line_, color_vertex_;
};
}  // namespace s21

#endif  // VIEWER_H
