/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFile;
    QAction *actionLoad;
    QAction *actionNew;
    QAction *actioninterface_ui;
    QAction *actionnew_ui;
    QAction *actioninterface_ui_2;
    QAction *actionnew_ui_2;
    QAction *actionSave_2;
    QWidget *centralwidget;
    QPushButton *pushButton;
    QDial *dial;
    QPushButton *helloMF;
    QProgressBar *progressBar;
    QSlider *horizontalSlider;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLineEdit *lineEdit_9;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QLineEdit *lineEdit_10;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_11;
    QLineEdit *lineEdit_11;
    QPushButton *pushButton_7;
    QTextEdit *textEditConsole;
    QWidget *page_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_12;
    QLineEdit *lineEdit_12;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_13;
    QLineEdit *lineEdit_13;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_14;
    QLineEdit *lineEdit_14;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_15;
    QLineEdit *lineEdit_15;
    QPushButton *pushButton_5;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_16;
    QLineEdit *lineEdit_16;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_17;
    QLineEdit *lineEdit_17;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_18;
    QLineEdit *lineEdit_18;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_19;
    QLineEdit *lineEdit_19;
    QPushButton *pushButton_6;
    QWidget *page_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEditConsole_2;
    QLineEdit *lineEdit_20;
    QPushButton *pushButton_8;
    QMenuBar *menubar;
    QMenu *menuHello_Motha_Fucka;
    QMenu *menuRecent_2;
    QMenu *menuEdit;
    QStatusBar *statusbar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(749, 982);
        MainWindow->setMinimumSize(QSize(749, 0));
        MainWindow->setMaximumSize(QSize(749, 16777215));
        MainWindow->setMouseTracking(true);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("face-kiss");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowOpacity(1.000000000000000);
        MainWindow->setStyleSheet(QString::fromUtf8("/*\n"
" * Mumble Dark Theme\n"
" * https://github.com/mumble-voip/mumble-theme\n"
" *\n"
" * Based on MetroMumble Theme by xPoke\n"
" * https://github.com/xPoke\n"
" *\n"
" * Originally forked from Flat Mumble Theme by xPaw (xpaw.ru)\n"
" *\n"
" * Licensed under The Do What The Fuck You Want To Public License (WTFPL)\n"
" */\n"
"/*\n"
" * YOU SHOULD NOT MODIFY THIS FILE\n"
" * Edit the files in the \"source\" folder instead.\n"
" * See project README\n"
" *\n"
" */\n"
"ApplicationPalette {\n"
"  qproperty-window: #2e2e2e;\n"
"  qproperty-windowtext: #eee;\n"
"  qproperty-windowtext_disabled: #484848;\n"
"  qproperty-base: #191919;\n"
"  qproperty-alternatebase: #2d2d2d;\n"
"  qproperty-text: #d8d8d8;\n"
"  qproperty-text_disabled: #484848;\n"
"  qproperty-tooltipbase: #191919;\n"
"  qproperty-tooltiptext: #d8d8d8;\n"
"  qproperty-tooltiptext_disabled: #484848;\n"
"  qproperty-brighttext: #FFF;\n"
"  qproperty-brighttext_disabled: #484848;\n"
"  qproperty-highlight: #298ce1;\n"
"  qproperty-highlightedtext: #FF"
                        "F;\n"
"  qproperty-highlightedtext_disabled: #484848;\n"
"  qproperty-button: #444;\n"
"  qproperty-buttontext: #d8d8d8;\n"
"  qproperty-buttontext_disabled: #484848;\n"
"  qproperty-link: #39a5dd;\n"
"  qproperty-linkvisited: #39a5dd;\n"
"  qproperty-light: #1c1c1c;\n"
"  qproperty-midlight: transparent;\n"
"  qproperty-mid: #1c1c1c;\n"
"  qproperty-dark: transparent;\n"
"  qproperty-shadow: #1c1c1c;\n"
"}\n"
"\n"
"QObject,\n"
"QObject::separator,\n"
"QObject::handle,\n"
"QObject::tab-bar,\n"
"QObject::tab,\n"
"QObject::section {\n"
"  font-family: \"Segoe UI\", Frutiger, \"Frutiger Linotype\", \"Dejavu Sans\", \"Helvetica Neue\", Arial, sans-serif;\n"
"  font-size: 10pt;\n"
"  margin: 0;\n"
"  padding: 0;\n"
"  outline: 0;\n"
"  border: 0;\n"
"  selection-background-color: #298ce1;\n"
"  selection-color: #FFF;\n"
"  alternate-background-color: transparent;\n"
"  color: #eee;\n"
"  border-radius: 2px;\n"
"}\n"
"\n"
"QMainWindow,\n"
"QDockWidget {\n"
"  background-color: #2e2e2e;\n"
"}\n"
"\n"
"QDialog,\n"
"QW"
                        "izard *,\n"
"QCalendarWidget *,\n"
"#qswPages > QObject {\n"
"  background-color: #1D1D1D;\n"
"  color: #d8d8d8;\n"
"}\n"
"\n"
"QObject:disabled,\n"
"QObject::item:disabled {\n"
"  color: #484848;\n"
"}\n"
"\n"
"a {\n"
"  color: #39a5dd;\n"
"  text-decoration: none;\n"
"}\n"
"\n"
"QObject::separator {\n"
"  height: 4px;\n"
"  width: 4px;\n"
"}\n"
"\n"
"QObject::separator:hover {\n"
"  background: #333;\n"
"}\n"
"\n"
"DockTitleBar {\n"
"  font-size: 7pt;\n"
"}\n"
"\n"
"QToolTip,\n"
"QWhatsThis {\n"
"  font-size: 8pt;\n"
"  min-height: 1.3em;\n"
"  border: 1px solid #888;\n"
"  border-radius: 0;\n"
"  background-color: #191919;\n"
"  color: #d8d8d8;\n"
"}\n"
"\n"
"QTextBrowser,\n"
"QTextEdit {\n"
"  background-color: #191919;\n"
"  color: #d8d8d8;\n"
"  border: 1px solid #1c1c1c;\n"
"}\n"
"\n"
"QToolBar {\n"
"  background-color: #2e2e2e;\n"
"  spacing: 0;\n"
"  padding: 2px;\n"
"}\n"
"\n"
"QToolButton {\n"
"  border: 1px solid transparent;\n"
"  border-radius: 2px;\n"
"  padding: 1px;\n"
"  margin: 1px;\n"
"}\n"
""
                        "\n"
"QToolButton:on {\n"
"  background-color: #444;\n"
"  border: 1px solid #444;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"  background-color: #3e4f5e;\n"
"  border: 1px solid #3e4f5e;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"  background-color: #484848;\n"
"}\n"
"\n"
"QToolBar::separator {\n"
"  background: #555;\n"
"  height: 1px;\n"
"  margin: 4px;\n"
"  width: 1px;\n"
"}\n"
"\n"
"QToolBar::separator:hover {\n"
"  background: #555;\n"
"  border: 0;\n"
"}\n"
"\n"
"QToolButton#qt_toolbar_ext_button {\n"
"  min-width: 8px;\n"
"  width: 8px;\n"
"  padding: 1px;\n"
"  qproperty-icon: url(skin:controls/toolbar_ext.svg);\n"
"}\n"
"\n"
"QToolBar::handle:horizontal {\n"
"  image: url(skin:controls/handle_horizontal.svg);\n"
"  width: 8px;\n"
"  padding: 4px;\n"
"}\n"
"\n"
"QToolBar::handle:vertical {\n"
"  image: url(skin:controls/handle_vertical.svg);\n"
"  height: 8px;\n"
"  padding: 4px;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"  background-color: transparent;\n"
"  padding: 4px 12px;\n"
"}\n"
"\n"
"QMenuBar::item:selec"
                        "ted {\n"
"  background: #298ce1;\n"
"  color: #FFF;\n"
"}\n"
"\n"
"QMenuBar::item:pressed {\n"
"  background: #1979ca;\n"
"  color: #FFF;\n"
"}\n"
"\n"
"QMenu {\n"
"  background: #2b2b2b;\n"
"  border: 1px solid #1c1c1c;\n"
"  color: #d8d8d8;\n"
"}\n"
"\n"
"QMenu::item {\n"
"  border: 1px solid transparent;\n"
"  color: #d8d8d8;\n"
"  padding: 5px 16px;\n"
"  padding-left: 25px;\n"
"  border-radius: 2px;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"  background: #3e4f5e;\n"
"  border: 1px solid #3e4f5e;\n"
"}\n"
"\n"
"QMenu::item:disabled {\n"
"  border: 1px solid transparent;\n"
"  background: transparent;\n"
"}\n"
"\n"
"QMenu::separator {\n"
"  background: #555;\n"
"  height: 1px;\n"
"}\n"
"\n"
"QMenu::indicator {\n"
"  padding-top: 2px;\n"
"  height: 25px;\n"
"  width: 25px;\n"
"}\n"
"\n"
"QPushButton {\n"
"  background-color: #444;\n"
"  border: 1px solid #444;\n"
"  color: #d8d8d8;\n"
"  font-size: 12pt;\n"
"  padding: 3px 20px;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"  background-color: #3e4f5e;\n"
"}\n"
"\n"
""
                        "QPushButton:hover {\n"
"  background-color: #595959;\n"
"  border-color: #555;\n"
"}\n"
"\n"
"QPushButton:hover:focus {\n"
"  background-color: #485d6f;\n"
"  border-color: #485d6f;\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"  border-color: #3e4f5e;\n"
"}\n"
"\n"
"QPushButton:pressed,\n"
"QPushButton:pressed:focus {\n"
"  background-color: #298ce1;\n"
"  border-color: #298ce1;\n"
"  color: #FFF;\n"
"}\n"
"\n"
"QGroupBox,\n"
"#qwMacWarning,\n"
"#qwInlineNotice {\n"
"  background-color: #2d2d2d;\n"
"  border: 1px solid #1c1c1c;\n"
"  color: #d8d8d8;\n"
"  font-size: 13pt;\n"
"  padding: 4px;\n"
"  padding-top: 1em;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"  background-color: transparent;\n"
"  margin: 6px;\n"
"  margin-left: 8px;\n"
"  margin-right: 8px;\n"
"}\n"
"\n"
"QListView {\n"
"  background-color: #191919;\n"
"  border: 1px solid #1c1c1c;\n"
"}\n"
"\n"
"QListView::item {\n"
"  border-radius: 2px;\n"
"  border: 1px solid transparent;\n"
"  color: #d8d8d8;\n"
"  selection-color: #d8d8d8;\n"
"  padding: 2px 4px;\n"
""
                        "}\n"
"\n"
"QListView::item:hover {\n"
"  background-color: #333;\n"
"  border: 1px solid #333;\n"
"}\n"
"\n"
"QListView::item:selected {\n"
"  background-color: #3b3b3b;\n"
"  border: 1px solid #3b3b3b;\n"
"}\n"
"\n"
"QListView::item:selected:active {\n"
"  background-color: #3e4f5e;\n"
"  border: 1px solid #3e4f5e;\n"
"}\n"
"\n"
"QTreeView {\n"
"  background-color: #191919;\n"
"  color: #d8d8d8;\n"
"  selection-background-color: #191919;\n"
"  selection-color: #d8d8d8;\n"
"  border: 1px solid #1c1c1c;\n"
"}\n"
"\n"
"QTreeView::item {\n"
"  min-width: 60px;\n"
"  border: 1px solid transparent;\n"
"  border-left: 0;\n"
"  border-right: 0;\n"
"  color: #d8d8d8;\n"
"  padding: 2px 4px;\n"
"  selection-color: #d8d8d8;\n"
"  border-radius: 0;\n"
"}\n"
"\n"
"QTreeView::item:first,\n"
"QTreeView::item:only-one {\n"
"  border-left: 1px solid transparent;\n"
"  border-top-left-radius: 2px;\n"
"  border-bottom-left-radius: 2px;\n"
"}\n"
"\n"
"QTreeView::item:last,\n"
"QTreeView::item:only-one {\n"
"  border-right: 1px s"
                        "olid transparent;\n"
"  border-top-right-radius: 2px;\n"
"  border-bottom-right-radius: 2px;\n"
"}\n"
"\n"
"QTreeView::item:hover,\n"
"QTreeView::item:focus {\n"
"  background-color: #333;\n"
"  border-color: #333;\n"
"}\n"
"\n"
"QTreeView::item:selected {\n"
"  background-color: #3b3b3b;\n"
"  border: 1px solid #3b3b3b;\n"
"  border-right: 0;\n"
"  border-left: 0;\n"
"}\n"
"\n"
"QTreeView::item:selected:first,\n"
"QTreeView::item:selected:only-one {\n"
"  border-left: 1px solid #3b3b3b;\n"
"}\n"
"\n"
"QTreeView::item:selected:last,\n"
"QTreeView::item:selected:only-one {\n"
"  border-right: 1px solid #3b3b3b;\n"
"}\n"
"\n"
"QTreeView::item:selected:active {\n"
"  background-color: #3e4f5e;\n"
"  border: 1px solid #3e4f5e;\n"
"  border-right: 0;\n"
"  border-left: 0;\n"
"}\n"
"\n"
"QTreeView::item:selected:active:first,\n"
"QTreeView::item:selected:active:only-one {\n"
"  border-left: 1px solid #3e4f5e;\n"
"}\n"
"\n"
"QTreeView::item:selected:active:last,\n"
"QTreeView::item:selected:active:only-one {\n"
"  bo"
                        "rder-right: 1px solid #3e4f5e;\n"
"}\n"
"\n"
"QTreeView::branch {\n"
"  border-image: none;\n"
"  image: none;\n"
"  margin-left: 3px;\n"
"  margin-top: 1px;\n"
"  padding-left: 3px;\n"
"}\n"
"\n"
"QTreeView::branch:has-children:closed {\n"
"  image: url(skin:controls/branch_closed.svg);\n"
"}\n"
"\n"
"QTreeView::branch:has-children:open {\n"
"  image: url(skin:controls/branch_open.svg);\n"
"}\n"
"\n"
"QHeaderView {\n"
"  border-bottom: 1px solid #1c1c1c;\n"
"  border-radius: 0;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"  border: 0;\n"
"  background-color: #2d2d2d;\n"
"  color: #d8d8d8;\n"
"  padding: 4px;\n"
"  padding-left: 8px;\n"
"  padding-right: 20px;\n"
"  border-radius: 0;\n"
"}\n"
"\n"
"QHeaderView::down-arrow,\n"
"QHeaderView::up-arrow {\n"
"  margin: 1px;\n"
"  top: 1px;\n"
"  right: 5px;\n"
"  width: 14px;\n"
"}\n"
"\n"
"QHeaderView::down-arrow {\n"
"  image: url(skin:controls/arrow_down.svg);\n"
"}\n"
"\n"
"QHeaderView::up-arrow {\n"
"  image: url(skin:controls/arrow_up.svg);\n"
"}\n"
"\n"
"QTabWi"
                        "dget::pane {\n"
"  background-color: #2d2d2d;\n"
"  border: 1px solid #1c1c1c;\n"
"}\n"
"\n"
"QTabWidget::pane:top {\n"
"  margin-top: -1px;\n"
"  border-radius: 2px;\n"
"  border-top-left-radius: 0;\n"
"}\n"
"\n"
"QTabWidget::pane:bottom {\n"
"  margin-bottom: -1px;\n"
"  border-radius: 2px;\n"
"  border-bottom-left-radius: 0;\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"  background-color: #1D1D1D;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"  color: #ccc;\n"
"  background-color: #1e1e1e;\n"
"  padding: 6px 16px;\n"
"  border-radius: 0;\n"
"  border: 1px solid #1c1c1c;\n"
"  border-right: 0;\n"
"}\n"
"\n"
"QTabBar::tab:last,\n"
"QTabBar::tab:only-one {\n"
"  border-right: 1px solid #1c1c1c;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"  background-color: #3e4f5e;\n"
"}\n"
"\n"
"QTabBar::tab:disabled {\n"
"  color: #484848;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"  color: #d8d8d8;\n"
"  background-color: #2d2d2d;\n"
"}\n"
"\n"
"QTabBar::tab:top {\n"
"  border-bottom: 0;\n"
"  margin-bottom: 1px;\n"
"}\n"
"\n"
"QTabBar::tab:b"
                        "ottom {\n"
"  border-top: 0;\n"
"  margin-top: 1px;\n"
"}\n"
"\n"
"QTabBar::tab:top:selected {\n"
"  padding-bottom: 7px;\n"
"  margin-bottom: 0;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:selected {\n"
"  padding-top: 7px;\n"
"  margin-top: 0;\n"
"}\n"
"\n"
"QTabBar::tab:top:first,\n"
"QTabBar::tab:top:only-one {\n"
"  border-top-left-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:top:last,\n"
"QTabBar::tab:top:only-one {\n"
"  border-top-right-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:first,\n"
"QTabBar::tab:bottom:only-one {\n"
"  border-bottom-left-radius: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:last,\n"
"QTabBar::tab:bottom:only-one {\n"
"  border-bottom-right-radius: 2px;\n"
"}\n"
"\n"
"QScrollBar {\n"
"  border-radius: 0;\n"
"  font-size: 10pt;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"  border-left: 1px solid #1c1c1c;\n"
"  width: 1em;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"  border-top: 1px solid #1c1c1c;\n"
"  height: 1em;\n"
"}\n"
"\n"
"QScrollBar::handle {\n"
"  margin: -1px;\n"
"  background: #666;\n"
""
                        "  border: 1px solid #1c1c1c;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"  min-height: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"  min-width: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:hover {\n"
"  background: #888;\n"
"}\n"
"\n"
"QScrollBar::left-arrow,\n"
"QScrollBar::right-arrow,\n"
"QScrollBar::up-arrow,\n"
"QScrollBar::down-arrow,\n"
"QScrollBar::sub-line,\n"
"QScrollBar::add-line,\n"
"QScrollBar::add-page,\n"
"QScrollBar::sub-page {\n"
"  background: #2e2e2e;\n"
"  height: 0;\n"
"  width: 0;\n"
"  border-radius: 0;\n"
"  border: 0;\n"
"}\n"
"\n"
"QAbstractScrollArea::corner {\n"
"  border-left: 1px solid #1c1c1c;\n"
"  border-top: 1px solid #1c1c1c;\n"
"  height: 0;\n"
"  width: 0;\n"
"  border-radius: 0;\n"
"  border-top: 1px solid #1c1c1c;\n"
"  border-left: 1px solid #1c1c1c;\n"
"  background: #191919;\n"
"}\n"
"\n"
"QLineEdit,\n"
"QComboBox,\n"
"QSpinBox,\n"
"QAbstractSpinBox {\n"
"  color: #d8d8d8;\n"
"  padding: 4px;\n"
"  min-height: 1em;\n"
"}\n"
"\n"
"QComboBox,\n"
"QSpinBox,\n"
""
                        "QAbstractSpinBox {\n"
"  border: 1px solid #444;\n"
"  background-color: #444;\n"
"}\n"
"\n"
"QLineEdit,\n"
"QTextEdit,\n"
"QPlainTextEdit,\n"
"QSpinBox,\n"
"QAbstractSpinBox,\n"
"QComboBox:editable {\n"
"  border: 1px solid #2e2e2e;\n"
"  background-color: #191919;\n"
"}\n"
"\n"
"QSpinBox,\n"
"QAbstractSpinBox {\n"
"  min-width: 2.5em;\n"
"  padding-right: 10px;\n"
"}\n"
"\n"
"QPushButton:disabled,\n"
"QLineEdit:disabled,\n"
"QTextEdit:disabled,\n"
"QPlainTextEdit:disabled,\n"
"QListWidget:disabled,\n"
"QTreeWidget:disabled,\n"
"QComboBox:disabled,\n"
"QSpinBox:disabled,\n"
"QAbstractSpinBox:disabled {\n"
"  border: 1px solid transparent;\n"
"  background-color: #282828;\n"
"}\n"
"\n"
"QComboBox::drop-down,\n"
"QAbstractSpinBox::drop-down,\n"
"QSpinBox::drop-down,\n"
"QDateTimeEdit::drop-down {\n"
"  background-color: #191919;\n"
"  border: 0;\n"
"  margin-left: 4px;\n"
"  margin-right: 12px;\n"
"  margin-top: 5px;\n"
"}\n"
"\n"
"QComboBox::down-arrow,\n"
"QDateTimeEdit::down-arrow {\n"
"  margin-top: -2px;\n"
""
                        "  image: url(skin:controls/arrow_down.svg);\n"
"  width: 14px;\n"
"}\n"
"\n"
"QComboBox::down-arrow:disabled,\n"
"QDateTimeEdit::down-arrow:disabled {\n"
"  image: url(skin:controls/arrow_down_disabled.svg);\n"
"}\n"
"\n"
"QToolButton[popupMode=\"1\"],\n"
"QToolButton[popupMode=\"2\"],\n"
"QPushButton[popupMode=\"1\"],\n"
"QPushButton[popupMode=\"2\"] {\n"
"  padding-right: 14px;\n"
"}\n"
"\n"
"QToolButton::menu-arrow,\n"
"QToolButton::menu-indicator,\n"
"QPushButton::menu-arrow,\n"
"QPushButton::menu-indicator {\n"
"  image: url(skin:controls/arrow_down.svg);\n"
"  subcontrol-origin: padding;\n"
"  subcontrol-position: center right;\n"
"  top: 2px;\n"
"  right: 2px;\n"
"  width: 14px;\n"
"}\n"
"\n"
"QSpinBox::down-button,\n"
"QAbstractSpinBox::down-button {\n"
"  padding-right: 4px;\n"
"  image: url(skin:controls/arrow_down.svg);\n"
"  width: 14px;\n"
"  padding-bottom: 1px;\n"
"}\n"
"\n"
"QSpinBox::down-button:disabled,\n"
"QAbstractSpinBox::down-button:disabled {\n"
"  image: url(skin:controls/arrow_down_di"
                        "sabled.svg);\n"
"}\n"
"\n"
"QSpinBox::up-button,\n"
"QAbstractSpinBox::up-button {\n"
"  padding-right: 4px;\n"
"  image: url(skin:controls/arrow_up.svg);\n"
"  width: 14px;\n"
"  padding-top: 1px;\n"
"}\n"
"\n"
"QSpinBox::up-button:disabled,\n"
"QAbstractSpinBox::up-button:disabled {\n"
"  image: url(skin:controls/arrow_up_disabled.svg);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"  background-color: #191919;\n"
"  border: 1px solid #1c1c1c;\n"
"  color: #d8d8d8;\n"
"  border-radius: 0;\n"
"}\n"
"\n"
"QLabel,\n"
"QCheckBox,\n"
"QAbstractCheckBox,\n"
"QTreeView::indicator,\n"
"QRadioButton {\n"
"  color: #d8d8d8;\n"
"  background: transparent;\n"
"}\n"
"\n"
"QCheckBox::indicator,\n"
"QTreeView::indicator {\n"
"  background-color: #444;\n"
"  border: 1px solid #444;\n"
"  height: 13px;\n"
"  width: 13px;\n"
"  margin-top: 1px;\n"
"}\n"
"\n"
"QMenu::indicator {\n"
"  width: 12px;\n"
"  left: 6px;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked,\n"
"QMenu::indicator:checked,\n"
"QTreeView::indicator:checked {\n"
""
                        "  image: url(skin:controls/checkbox_check_dark.svg);\n"
"}\n"
"\n"
"QCheckBox::indicator:disabled,\n"
"QTreeView::indicator:disabled {\n"
"  border: 1px solid #2d2d2d;\n"
"  background-color: #282828;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:disabled,\n"
"QTreeView::indicator:checked:disabled {\n"
"  border: 1px solid transparent;\n"
"  image: url(skin:controls/checkbox_check_disabled.svg);\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"  background: #444;\n"
"  border: 1px solid #444;\n"
"  border-radius: 7px;\n"
"  height: 12px;\n"
"  width: 12px;\n"
"}\n"
"\n"
"QTreeView::indicator {\n"
"  background: #444;\n"
"}\n"
"\n"
"QRadioButton::indicator:disabled {\n"
"  background-color: #282828;\n"
"  margin: 1px;\n"
"  border: 1px solid transparent;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"  image: url(skin:controls/radio_check_dark.svg);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:disabled {\n"
"  image: url(skin:controls/radio_check_disabled.svg);\n"
"}\n"
"\n"
"QSlider::groove {\n"
"  backgroun"
                        "d: #393939;\n"
"  border: 1px solid #393939;\n"
"  border-radius: 2px;\n"
"  font-size: 3pt;\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"  height: 0.8em;\n"
"}\n"
"\n"
"QSlider::groove:vertical {\n"
"  width: 0.8em;\n"
"}\n"
"\n"
"QSlider::groove:disabled,\n"
"QSlider::sub-page:disabled {\n"
"  background: #282828;\n"
"  border: 1px solid transparent;\n"
"  border-radius: 2px;\n"
"}\n"
"\n"
"QSlider::sub-page {\n"
"  background: #486d8d;\n"
"  border: 1px solid #486d8d;\n"
"  border-radius: 2px;\n"
"}\n"
"\n"
"QSlider::handle {\n"
"  background: #777;\n"
"  border: 1px solid #222;\n"
"  border-radius: 3px;\n"
"  font-size: 4pt;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"  margin: -5px -1px;\n"
"  width: 4.5em;\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"  margin: -1px -5px;\n"
"  height: 4.5em;\n"
"}\n"
"\n"
"QSlider::handle:focus {\n"
"  background-color: #6d96ba;\n"
"  border-color: #226;\n"
"}\n"
"\n"
"QSlider::handle:hover {\n"
"  background-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:pressed {\n"
""
                        "  background-color: #bbb;\n"
"  border-color: #222;\n"
"}\n"
"\n"
"QSlider::handle:disabled {\n"
"  background-color: #282828;\n"
"  border: 1px solid #282828;\n"
"}\n"
"\n"
"QCheckBox::indicator:focus,\n"
"QTreeView::indicator:focus,\n"
"QRadioButton::indicator:focus,\n"
"QComboBox:focus {\n"
"  background-color: #3e4f5e;\n"
"}\n"
"\n"
"QCheckBox::indicator:focus:hover,\n"
"QTreeView::indicator:focus:hover,\n"
"QRadioButton::indicator:focus:hover,\n"
"QComboBox:focus:hover {\n"
"  background-color: #485d6f;\n"
"  border-color: #485d6f;\n"
"}\n"
"\n"
"QCheckBox::indicator:hover,\n"
"QTreeView::indicator:hover,\n"
"QRadioButton::indicator:hover,\n"
"QComboBox:hover {\n"
"  background-color: #595959;\n"
"  border-color: #555;\n"
"}\n"
"\n"
"QLineEdit:focus,\n"
"QSpinBox:focus,\n"
"QAbstractSpinBox:focus,\n"
"QComboBox:editable:focus {\n"
"  background-color: #191919;\n"
"}\n"
"\n"
"QLineEdit:focus:hover,\n"
"QSpinBox:focus:hover,\n"
"QAbstractSpinBox:focus:hover,\n"
"QComboBox:editable:focus:hover {\n"
"  border"
                        "-color: #485d6f;\n"
"}\n"
"\n"
"QLineEdit:hover,\n"
"QSpinBox:hover,\n"
"QAbstractSpinBox:hover,\n"
"QComboBox:editable:hover {\n"
"  background-color: #191919;\n"
"  border-color: #555;\n"
"}\n"
"\n"
"QCheckBox::indicator:focus,\n"
"QTreeView::indicator:focus,\n"
"QRadioButton::indicator:focus,\n"
"QComboBox:focus,\n"
"QLineEdit:focus,\n"
"QTextEdit:focus,\n"
"QPlainTextEdit:focus,\n"
"QSpinBox:focus,\n"
"QAbstractSpinBox:focus,\n"
"QComboBox:editable:focus {\n"
"  border-color: #3e4f5e;\n"
"}\n"
"\n"
"QFontDialog {\n"
"  min-width: 32em;\n"
"  min-height: 24em;\n"
"}\n"
"\n"
"QColorDialog QColorLuminancePicker {\n"
"  background-color: transparent;\n"
"}\n"
"\n"
"QMessageBox,\n"
"QDialogButtonBox {\n"
"  dialogbuttonbox-buttons-have-icons: 0;\n"
"}\n"
"\n"
"/* Mumble Specifics */\n"
"LogTextBrowser,\n"
"#qdsChat {\n"
"  margin: 0 2px;\n"
"  min-height: 120px;\n"
"  min-width: 40px;\n"
"  border-color: #1c1c1c;\n"
"}\n"
"\n"
"UserView {\n"
"  margin: 0 2px;\n"
"  min-height: 120px;\n"
"  min-width: 40px;\n"
""
                        "}\n"
"\n"
"UserView::item {\n"
"  padding: 0;\n"
"  padding-top: -1px;\n"
"}\n"
"\n"
"#qdwChat > QTextEdit {\n"
"  padding: -2px;\n"
"  margin: 0 2px;\n"
"  margin-bottom: 2px;\n"
"  font-size: 10pt;\n"
"}\n"
"\n"
"#qtIconToolbar QComboBox {\n"
"  font-size: 8pt;\n"
"}\n"
"\n"
".log-time {\n"
"  background-color: transparent;\n"
"  color: #95a5a6;\n"
"  font-size: 9pt;\n"
"}\n"
"\n"
".log-server {\n"
"  background-color: transparent;\n"
"  color: #F9655D;\n"
"  font-weight: bold;\n"
"}\n"
"\n"
".log-channel {\n"
"  background-color: transparent;\n"
"  color: #e67e22;\n"
"  font-weight: bold;\n"
"}\n"
"\n"
".log-privilege {\n"
"  background-color: transparent;\n"
"  color: #c0392b;\n"
"  font-weight: bold;\n"
"}\n"
"\n"
".log-target {\n"
"  background-color: transparent;\n"
"  color: #27ae60;\n"
"  font-weight: bold;\n"
"}\n"
"\n"
".log-source {\n"
"  background-color: transparent;\n"
"  color: #27ae60;\n"
"  font-weight: bold;\n"
"}\n"
"\n"
"QListView#qlwIcons {\n"
"  padding: 0;\n"
"  background-color: transp"
                        "arent;\n"
"  border: 0;\n"
"  font-size: 12pt;\n"
"  min-width: 165%;\n"
"  margin-left: 4px;\n"
"  margin-top: 12px;\n"
"}\n"
"\n"
"QListView#qlwIcons::item {\n"
"  margin-bottom: 1px;\n"
"  padding: 5px 7px;\n"
"}\n"
"\n"
"QListView#qlwIcons::item:hover {\n"
"  border-color: #333;\n"
"  background-color: #333;\n"
"}\n"
"\n"
"QListView#qlwIcons::item:selected {\n"
"  background-color: #444;\n"
"  border: 1px solid #444;\n"
"}\n"
"\n"
"QListView#qlwIcons::item:focus {\n"
"  background-color: #3e4f5e;\n"
"  border: 1px solid #3e4f5e;\n"
"}\n"
"\n"
"QSlider {\n"
"  margin-left: 30px;\n"
"  margin-right: 30px;\n"
"}\n"
"\n"
"#qswPages > * > * > QScrollBar {\n"
"  margin: 0;\n"
"}\n"
"\n"
"#qswPages > * > QWidget {\n"
"  margin: 2px;\n"
"}\n"
"\n"
"QListView::item QListWidgetItem,\n"
"QListView::item QLineEdit,\n"
"QTreeView::item QComboBox,\n"
"QTreeView::item QLineEdit {\n"
"  background: #444;\n"
"  margin: 0;\n"
"  padding-top: 0;\n"
"  padding-bottom: 0;\n"
"  padding-left: 4px;\n"
"  padding-right: 4px;\n"
""
                        "  font-size: 9pt;\n"
"}\n"
"\n"
"QListView::item QListWidgetItem:hover,\n"
"QListView::item QLineEdit:hover,\n"
"QTreeView::item QComboBox:hover,\n"
"QTreeView::item QLineEdit:hover {\n"
"  background: #444;\n"
"}\n"
"\n"
"AboutDialog > QTextBrowser,\n"
"AboutDialog QTextEdit {\n"
"  border: 0;\n"
"}\n"
"\n"
"#qtbToolBar {\n"
"  border: 1px solid transparent;\n"
"  background: transparent;\n"
"}\n"
"\n"
"#BanEditor {\n"
"  min-width: 600px;\n"
"}\n"
"\n"
"#GlobalShortcutTarget {\n"
"  min-height: 600px;\n"
"}\n"
"\n"
"ViewCert {\n"
"  min-height: 600px;\n"
"}\n"
"\n"
"TalkingUI {\n"
"  background-color: #191919;\n"
"}\n"
"\n"
"TalkingUI > * {\n"
"  background-color: #191919;\n"
"}\n"
"\n"
"TalkingUI [selected=\"false\"] {\n"
"  background-color: #191919;\n"
"}\n"
"\n"
"TalkingUI [selected=\"false\"]:hover {\n"
"  background-color: #333;\n"
"}\n"
"\n"
"TalkingUI [selected=\"true\"] {\n"
"  background-color: #3e4f5e;\n"
"  border: 1px solid #3e4f5e;\n"
"}\n"
"\n"
"TalkingUI > QFrame {\n"
"  border: 1px solid;\n"
""
                        "  border-color: #1c1c1c;\n"
"  border-radius: 2px;\n"
"}\n"
"\n"
"/*# sourceMappingURL=Dark.qss.map */"));
        actionFile = new QAction(MainWindow);
        actionFile->setObjectName("actionFile");
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName("actionLoad");
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        actioninterface_ui = new QAction(MainWindow);
        actioninterface_ui->setObjectName("actioninterface_ui");
        actionnew_ui = new QAction(MainWindow);
        actionnew_ui->setObjectName("actionnew_ui");
        actioninterface_ui_2 = new QAction(MainWindow);
        actioninterface_ui_2->setObjectName("actioninterface_ui_2");
        actionnew_ui_2 = new QAction(MainWindow);
        actionnew_ui_2->setObjectName("actionnew_ui_2");
        actionSave_2 = new QAction(MainWindow);
        actionSave_2->setObjectName("actionSave_2");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 810, 221, 30));
        dial = new QDial(centralwidget);
        dial->setObjectName("dial");
        dial->setGeometry(QRect(380, 830, 50, 64));
        helloMF = new QPushButton(centralwidget);
        helloMF->setObjectName("helloMF");
        helloMF->setGeometry(QRect(80, 770, 263, 32));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(160, 900, 118, 23));
        progressBar->setValue(1);
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(90, 860, 261, 20));
        horizontalSlider->setOrientation(Qt::Horizontal);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 10, 531, 751));
        page = new QWidget();
        page->setObjectName("page");
        layoutWidget_2 = new QWidget(page);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(10, 20, 384, 159));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_9 = new QLabel(layoutWidget_2);
        label_9->setObjectName("label_9");
        label_9->setMinimumSize(QSize(150, 0));

        horizontalLayout_9->addWidget(label_9);

        lineEdit_9 = new QLineEdit(layoutWidget_2);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setMinimumSize(QSize(200, 21));
        QPalette palette;
        QBrush brush(QColor(216, 216, 216, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(25, 25, 25, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(41, 140, 225, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        QBrush brush3(QColor(255, 255, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        QBrush brush4(QColor(0, 0, 0, 0));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush5(QColor(216, 216, 216, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        QBrush brush6(QColor(72, 72, 72, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        QBrush brush7(QColor(40, 40, 40, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush4);
        QBrush brush8(QColor(72, 72, 72, 128));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        lineEdit_9->setPalette(palette);
        lineEdit_9->setStyleSheet(QString::fromUtf8(""));
        lineEdit_9->setInputMethodHints(Qt::ImhHiddenText);
        lineEdit_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_9->setClearButtonEnabled(false);

        horizontalLayout_9->addWidget(lineEdit_9);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName("label_10");
        label_10->setMinimumSize(QSize(150, 0));

        horizontalLayout_10->addWidget(label_10);

        lineEdit_10 = new QLineEdit(layoutWidget_2);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setMinimumSize(QSize(200, 21));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        lineEdit_10->setPalette(palette1);
        lineEdit_10->setStyleSheet(QString::fromUtf8(""));
        lineEdit_10->setInputMethodHints(Qt::ImhHiddenText);
        lineEdit_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(lineEdit_10);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_11 = new QLabel(layoutWidget_2);
        label_11->setObjectName("label_11");
        label_11->setMinimumSize(QSize(150, 0));

        horizontalLayout_11->addWidget(label_11);

        lineEdit_11 = new QLineEdit(layoutWidget_2);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setMinimumSize(QSize(200, 21));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette2.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        lineEdit_11->setPalette(palette2);
        lineEdit_11->setStyleSheet(QString::fromUtf8(""));
        lineEdit_11->setInputMethodHints(Qt::ImhHiddenText);
        lineEdit_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(lineEdit_11);


        verticalLayout_4->addLayout(horizontalLayout_11);

        pushButton_7 = new QPushButton(page);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(400, 20, 93, 161));
        textEditConsole = new QTextEdit(page);
        textEditConsole->setObjectName("textEditConsole");
        textEditConsole->setGeometry(QRect(20, 210, 461, 531));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        layoutWidget = new QWidget(page_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 220, 362, 159));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName("label_12");
        label_12->setMinimumSize(QSize(150, 0));

        horizontalLayout_12->addWidget(label_12);

        lineEdit_12 = new QLineEdit(layoutWidget);
        lineEdit_12->setObjectName("lineEdit_12");
        lineEdit_12->setMinimumSize(QSize(200, 21));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette3.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        lineEdit_12->setPalette(palette3);
        lineEdit_12->setStyleSheet(QString::fromUtf8(""));
        lineEdit_12->setInputMethodHints(Qt::ImhHiddenText);
        lineEdit_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_12->setReadOnly(true);

        horizontalLayout_12->addWidget(lineEdit_12);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName("label_13");
        label_13->setMinimumSize(QSize(150, 0));

        horizontalLayout_13->addWidget(label_13);

        lineEdit_13 = new QLineEdit(layoutWidget);
        lineEdit_13->setObjectName("lineEdit_13");
        lineEdit_13->setMinimumSize(QSize(200, 21));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette4.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        lineEdit_13->setPalette(palette4);
        lineEdit_13->setStyleSheet(QString::fromUtf8(""));
        lineEdit_13->setInputMethodHints(Qt::ImhHiddenText);
        lineEdit_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_13->setReadOnly(true);

        horizontalLayout_13->addWidget(lineEdit_13);


        verticalLayout_5->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName("label_14");
        label_14->setMinimumSize(QSize(150, 0));

        horizontalLayout_14->addWidget(label_14);

        lineEdit_14 = new QLineEdit(layoutWidget);
        lineEdit_14->setObjectName("lineEdit_14");
        lineEdit_14->setMinimumSize(QSize(200, 21));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette5.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        lineEdit_14->setPalette(palette5);
        lineEdit_14->setStyleSheet(QString::fromUtf8(""));
        lineEdit_14->setInputMethodHints(Qt::ImhHiddenText);
        lineEdit_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_14->setReadOnly(true);

        horizontalLayout_14->addWidget(lineEdit_14);


        verticalLayout_5->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName("label_15");
        label_15->setMinimumSize(QSize(150, 0));

        horizontalLayout_15->addWidget(label_15);

        lineEdit_15 = new QLineEdit(layoutWidget);
        lineEdit_15->setObjectName("lineEdit_15");
        lineEdit_15->setMinimumSize(QSize(200, 21));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette6.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette6.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        lineEdit_15->setPalette(palette6);
        lineEdit_15->setStyleSheet(QString::fromUtf8(""));
        lineEdit_15->setInputMethodHints(Qt::ImhHiddenText);
        lineEdit_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_15->setReadOnly(true);

        horizontalLayout_15->addWidget(lineEdit_15);


        verticalLayout_5->addLayout(horizontalLayout_15);

        pushButton_5 = new QPushButton(page_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(390, 20, 93, 161));
        layoutWidget_3 = new QWidget(page_2);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(0, 20, 361, 174));
        verticalLayout_6 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        label_16 = new QLabel(layoutWidget_3);
        label_16->setObjectName("label_16");
        label_16->setMinimumSize(QSize(150, 0));

        horizontalLayout_16->addWidget(label_16);

        lineEdit_16 = new QLineEdit(layoutWidget_3);
        lineEdit_16->setObjectName("lineEdit_16");
        lineEdit_16->setMinimumSize(QSize(200, 21));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette7.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette7.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        lineEdit_16->setPalette(palette7);
        lineEdit_16->setStyleSheet(QString::fromUtf8(""));
        lineEdit_16->setInputMethodHints(Qt::ImhHiddenText);
        lineEdit_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_16->setClearButtonEnabled(false);

        horizontalLayout_16->addWidget(lineEdit_16);


        verticalLayout_6->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        label_17 = new QLabel(layoutWidget_3);
        label_17->setObjectName("label_17");
        label_17->setMinimumSize(QSize(150, 0));

        horizontalLayout_17->addWidget(label_17);

        lineEdit_17 = new QLineEdit(layoutWidget_3);
        lineEdit_17->setObjectName("lineEdit_17");
        lineEdit_17->setMinimumSize(QSize(200, 21));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette8.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette8.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette8.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        lineEdit_17->setPalette(palette8);
        lineEdit_17->setStyleSheet(QString::fromUtf8(""));
        lineEdit_17->setInputMethodHints(Qt::ImhHiddenText);
        lineEdit_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_17->addWidget(lineEdit_17);


        verticalLayout_6->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        label_18 = new QLabel(layoutWidget_3);
        label_18->setObjectName("label_18");
        label_18->setMinimumSize(QSize(150, 0));

        horizontalLayout_18->addWidget(label_18);

        lineEdit_18 = new QLineEdit(layoutWidget_3);
        lineEdit_18->setObjectName("lineEdit_18");
        lineEdit_18->setMinimumSize(QSize(200, 21));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette9.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette9.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette9.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        lineEdit_18->setPalette(palette9);
        lineEdit_18->setStyleSheet(QString::fromUtf8(""));
        lineEdit_18->setInputMethodHints(Qt::ImhHiddenText);
        lineEdit_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_18->addWidget(lineEdit_18);


        verticalLayout_6->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        label_19 = new QLabel(layoutWidget_3);
        label_19->setObjectName("label_19");
        label_19->setMinimumSize(QSize(150, 0));

        horizontalLayout_19->addWidget(label_19);

        lineEdit_19 = new QLineEdit(layoutWidget_3);
        lineEdit_19->setObjectName("lineEdit_19");
        lineEdit_19->setMinimumSize(QSize(200, 21));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette10.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette10.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette10.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        lineEdit_19->setPalette(palette10);
        lineEdit_19->setStyleSheet(QString::fromUtf8(""));
        lineEdit_19->setInputMethodHints(Qt::ImhHiddenText);
        lineEdit_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_19->addWidget(lineEdit_19);


        verticalLayout_6->addLayout(horizontalLayout_19);

        pushButton_6 = new QPushButton(page_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(390, 220, 93, 161));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        layoutWidget1 = new QWidget(page_3);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(30, 30, 481, 661));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        textEditConsole_2 = new QTextEdit(layoutWidget1);
        textEditConsole_2->setObjectName("textEditConsole_2");

        verticalLayout_2->addWidget(textEditConsole_2);

        lineEdit_20 = new QLineEdit(layoutWidget1);
        lineEdit_20->setObjectName("lineEdit_20");
        lineEdit_20->setMinimumSize(QSize(200, 21));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette11.setBrush(QPalette::Active, QPalette::HighlightedText, brush3);
        palette11.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette11.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        lineEdit_20->setPalette(palette11);
        lineEdit_20->setStyleSheet(QString::fromUtf8(""));
        lineEdit_20->setInputMethodHints(Qt::ImhHiddenText);
        lineEdit_20->setMaxLength(80000);
        lineEdit_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_20->setClearButtonEnabled(false);

        verticalLayout_2->addWidget(lineEdit_20);

        pushButton_8 = new QPushButton(layoutWidget1);
        pushButton_8->setObjectName("pushButton_8");

        verticalLayout_2->addWidget(pushButton_8);

        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralwidget);
        stackedWidget->raise();
        pushButton->raise();
        dial->raise();
        helloMF->raise();
        progressBar->raise();
        horizontalSlider->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 749, 20));
        menuHello_Motha_Fucka = new QMenu(menubar);
        menuHello_Motha_Fucka->setObjectName("menuHello_Motha_Fucka");
        menuRecent_2 = new QMenu(menuHello_Motha_Fucka);
        menuRecent_2->setObjectName("menuRecent_2");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName("dockWidget");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(250);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName("dockWidgetContents");
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setObjectName("verticalLayout");
        pushButton_2 = new QPushButton(dockWidgetContents);
        pushButton_2->setObjectName("pushButton_2");
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setMinimumSize(QSize(170, 0));
        pushButton_2->setMaximumSize(QSize(1000, 500));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(dockWidgetContents);
        pushButton_3->setObjectName("pushButton_3");
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setMaximumSize(QSize(1000, 500));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(dockWidgetContents);
        pushButton_4->setObjectName("pushButton_4");
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setMaximumSize(QSize(1000, 500));

        verticalLayout->addWidget(pushButton_4);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
        QWidget::setTabOrder(helloMF, pushButton);
        QWidget::setTabOrder(pushButton, dial);
        QWidget::setTabOrder(dial, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_4);

        menubar->addAction(menuHello_Motha_Fucka->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuHello_Motha_Fucka->addAction(actionNew);
        menuHello_Motha_Fucka->addAction(actionLoad);
        menuHello_Motha_Fucka->addAction(menuRecent_2->menuAction());
        menuHello_Motha_Fucka->addSeparator();
        menuHello_Motha_Fucka->addAction(actionSave_2);
        menuRecent_2->addAction(actioninterface_ui_2);
        menuRecent_2->addAction(actionnew_ui_2);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider, &QSlider::valueChanged, progressBar, &QProgressBar::setValue);
        QObject::connect(horizontalSlider, &QSlider::valueChanged, dial, &QDial::setValue);
        QObject::connect(dial, &QDial::valueChanged, horizontalSlider, &QSlider::setValue);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Mother fucking app", nullptr));
        actionFile->setText(QCoreApplication::translate("MainWindow", "File", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actioninterface_ui->setText(QCoreApplication::translate("MainWindow", "interface.ui", nullptr));
        actionnew_ui->setText(QCoreApplication::translate("MainWindow", "new.ui", nullptr));
        actioninterface_ui_2->setText(QCoreApplication::translate("MainWindow", "interface.ui", nullptr));
        actionnew_ui_2->setText(QCoreApplication::translate("MainWindow", "new.ui", nullptr));
        actionSave_2->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Python Fucker =)", nullptr));
        helloMF->setText(QCoreApplication::translate("MainWindow", "Hello Motherfucker =)", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "House price:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_9->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        lineEdit_9->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        lineEdit_9->setText(QCoreApplication::translate("MainWindow", "3000000", nullptr));
        lineEdit_9->setPlaceholderText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "Interest:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_10->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        lineEdit_10->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        lineEdit_10->setText(QCoreApplication::translate("MainWindow", "0.04", nullptr));
        lineEdit_10->setPlaceholderText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "Years to pay:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_11->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        lineEdit_11->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        lineEdit_11->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        lineEdit_11->setPlaceholderText(QString());
#if QT_CONFIG(whatsthis)
        pushButton_7->setWhatsThis(QCoreApplication::translate("MainWindow", "Adds food to meal", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Loan", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Fat compensation", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_12->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        lineEdit_12->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        lineEdit_12->setText(QString());
        lineEdit_12->setPlaceholderText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "Calories of meal", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_13->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        lineEdit_13->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        lineEdit_13->setText(QString());
        lineEdit_13->setPlaceholderText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "Fat compensation", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_14->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        lineEdit_14->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        lineEdit_14->setText(QString());
        lineEdit_14->setPlaceholderText(QString());
        label_15->setText(QCoreApplication::translate("MainWindow", "Calories of meal", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_15->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        lineEdit_15->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        lineEdit_15->setText(QString());
        lineEdit_15->setPlaceholderText(QString());
#if QT_CONFIG(whatsthis)
        pushButton_5->setWhatsThis(QCoreApplication::translate("MainWindow", "Adds food to meal", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Grams of food:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_16->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        lineEdit_16->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        lineEdit_16->setText(QCoreApplication::translate("MainWindow", "44", nullptr));
        lineEdit_16->setPlaceholderText(QString());
        label_17->setText(QCoreApplication::translate("MainWindow", "Carbs per 100g:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_17->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        lineEdit_17->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        lineEdit_17->setText(QCoreApplication::translate("MainWindow", "0.72", nullptr));
        lineEdit_17->setPlaceholderText(QString());
        label_18->setText(QCoreApplication::translate("MainWindow", "Protein per 100g:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_18->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        lineEdit_18->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        lineEdit_18->setText(QCoreApplication::translate("MainWindow", "12.6", nullptr));
        lineEdit_18->setPlaceholderText(QString());
        label_19->setText(QCoreApplication::translate("MainWindow", "Fat per 100g:", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_19->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        lineEdit_19->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        lineEdit_19->setText(QCoreApplication::translate("MainWindow", "9.51", nullptr));
        lineEdit_19->setPlaceholderText(QString());
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        textEditConsole_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI','Frutiger','Frutiger Linotype','Dejavu Sans','Helvetica Neue','Arial','sans-serif'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; line-height:19px; background-color:#2a2d33;\"><span style=\" font-family:'Droid Sans Mono','monospace','monospace'; font-size:14px; color:#ff6188;\">tickers</span><span style=\" font-family:'Droid Sans Mono','monospace','monospace'; font-size:14px; color:#c3c6cc;\"> </span><span style=\" font-family:'Droid Sans Mono','mo"
                        "nospace','monospace'; font-size:14px; color:#ffd866;\">=</span><span style=\" font-family:'Droid Sans Mono','monospace','monospace'; font-size:14px; color:#c3c6cc;\"> MMM,AOS,ABT,ABBV,ACN,ADBE,AMD,AES,AFL,A,APD,ABNB,AKAM,ALB,ARE,ALGN,ALLE,LNT,ALL,GOOGL,GOOG,MO,AMZN,AMCR,AEE,AAL,AEP,AXP,AIG,AMT,AWK,AMP,AME,AMGN,APH,ADI,ANSS,AON,APA,AAPL,AMAT,APTV,ACGL,ADM,ANET,AJG,AIZ,T,ATO,ADSK,ADP,AZO,AVB,AVY,AXON,BKR,BALL,BAC,BK,BBWI,BAX,BDX,BRK-B,BBY,BIO,TECH,BIIB,BLK,BX,BA,BKNG,BWA,BXP,BSX,BMY,AVGO,BR,BRO,BF-B,BLDR,BG,CDNS,CZR,CPT,CPB,COF,CAH,KMX,CCL,CARR,CTLT,CAT,CBOE,CBRE,CDW,CE,COR,CNC,CNP,CF,CHRW,CRL,SCHW,CHTR,CVX,CMG,CB,CHD,CI,CINF,CTAS,CSCO,C,CFG,CLX,CME,CMS,KO,CTSH,CL,CMCSA,CMA,CAG,COP,ED,STZ,CEG,COO,CPRT,GLW,CPAY,CTVA,CSGP,COST,CTRA,CCI,CSX,CMI,CVS,DHR,DRI,DVA,DAY,DECK,DE,DAL,DVN,DXCM,FANG,DLR,DFS,DG,DLTR,D,DPZ,DOV,DOW,DHI,DTE,DUK,DD,EMN,ETN,EBAY,ECL,EIX,EW,EA,ELV,LLY,EMR,ENPH,ETR,EOG,EPAM,EQT,EFX,EQIX,EQR,ESS,EL,ETSY,EG,EVRG,ES,EXC,EXPE,EXPD,EXR,XOM,FFIV,FDS,FICO,FAST,FRT,FDX,FIS,FITB,FSLR,FE,FI,FMC,F,FTNT,FTV,FOX"
                        "A,FOX,BEN,FCX,GRMN,IT,GE,GEHC,GEV,GEN,GNRC,GD,GIS,GM,GPC,GILD,GPN,GL,GS,HAL,HIG,HAS,HCA,DOC,HSIC,HSY,HES,HPE,HLT,HOLX,HD,HON,HRL,HST,HWM,HPQ,HUBB,HUM,HBAN,HII,IBM,IEX,IDXX,ITW,ILMN,INCY,IR,PODD,INTC,ICE,IFF,IP,IPG,INTU,ISRG,IVZ,INVH,IQV,IRM,JBHT,JBL,JKHY,J,JNJ,JCI,JPM,JNPR,K,KVUE,KDP,KEY,KEYS,KMB,KIM,KMI,KLAC,KHC,KR,LHX,LH,LRCX,LW,LVS,LDOS,LEN,LIN,LYV,LKQ,LMT,L,LOW,LULU,LYB,MTB,MRO,MPC,MKTX,MAR,MMC,MLM,MAS,MA,MTCH,MKC,MCD,MCK,MDT,MRK,META,MET,MTD,MGM,MCHP,MU,MSFT,MAA,MRNA,MHK,MOH,TAP,MDLZ,MPWR,MNST,MCO,MS,MOS,MSI,MSCI,NDAQ,NTAP,NFLX,NEM,NWSA,NWS,NEE,NKE,NI,NDSN,NSC,NTRS,NOC,NCLH,NRG,NUE,NVDA,NVR,NXPI,ORLY,OXY,ODFL,OMC,ON,OKE,ORCL,OTIS,PCAR,PKG,PANW,PARA,PH,PAYX,PAYC,PYPL,PNR,PEP,PFE,PCG,PM,PSX,PNW,PNC,POOL,PPG,PPL,PFG,PG,PGR,PLD,PRU,PEG,PTC,PSA,PHM,QRVO,PWR,QCOM,DGX,RL,RJF,RTX,O,REG,REGN,RF,RSG,RMD,RVTY,RHI,ROK,ROL,ROP,ROST,RCL,SPGI,CRM,SBAC,SLB,STX,SRE,NOW,SHW,SPG,SWKS,SJM,SNA,SOLV,SO,LUV,SWK,SBUX,STT,STLD,STE,SYK,SMCI,SYF,SNPS,SYY,TMUS,TROW,TTWO,TPR,TRGP,TGT,TEL,TDY,TFX,TER,TSLA,TXN,TXT,TMO,TJX,TSCO,TT,TDG,T"
                        "RV,TRMB,TFC,TYL,TSN,USB,UBER,UDR,ULTA,UNP,UAL,UPS,URI,UNH,UHS,VLO,VTR,VLTO,VRSN,VRSK,VZ,VRTX,VTRS,VICI,V,VST,VMC,WRB,GWW,WAB,WBA,WMT,DIS,WBD,WM,WAT,WEC,WFC,WELL,WST,WDC,WRK,WY,WMB,WTW,WYNN,XEL,XYL,YUM,ZBRA,ZBH,ZTS,</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_20->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        lineEdit_20->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        lineEdit_20->setText(QCoreApplication::translate("MainWindow", "TSM,MSFT,META,NVDA,GOOG,AMD,", nullptr));
        lineEdit_20->setPlaceholderText(QString());
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Calculate instrinsic values", nullptr));
        menuHello_Motha_Fucka->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuRecent_2->setTitle(QCoreApplication::translate("MainWindow", "Recent", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Loan", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Keto Calc", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Others", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
