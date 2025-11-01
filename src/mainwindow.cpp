/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "mainwindow.h"

#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QProgressBar>
#include <QSettings>
#include <QStatusBar>
#include <QToolBar>
#include <QToolButton>
#include <QVBoxLayout>
#include <QWidgetAction>

#include <qxaboutdialog.h>
#include <qxcomponentsdialog.h>
#include <qxconfirmationbox.h>
#include <qxrangeslider.h>
#include <qxtoolbarsdialog.h>
#include <qxtoolgroup.h>
#include <qxtoolpalette.h>
#include <qxzoombutton.h>

#include "aboutdialog/aboutdialogpageauthors.h"
#include "aboutdialog/aboutdialogpagecomponents.h"
#include "aboutdialog/aboutdialogpagecredits.h"
#include "aboutdialog/aboutdialogpagegeneral.h"
#include "aboutdialog/aboutdialogpagelicense.h"
#include "mediathekview.h"
#include "settingsdialog/settingsdialog.h"

using namespace Qt::Literals::StringLiterals;


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow{parent}
    , m_mediathekViewModel{new MediathekViewModel(this)}
    , m_mediathekViewView{new MediathekViewView(this)}
    , m_channelItemStyles{ChannelItemStyle::StrikeOut}
{

    setupUi();
    loadSettings();

    m_mediathekViewView->setModel(m_mediathekViewModel);
    setCentralWidget(m_mediathekViewView);

    setWindowIcon(QIcon::fromTheme("mediathekview-qt"_L1, QIcon(":/icons/apps/16/mediathekview-qt"_L1)));
    setMinimumSize(854, 480);

}

MainWindow::~MainWindow() {}


void MainWindow::setupUi()
{
    // File menu & toolbar

    QProgressBar* progressbarDownload = new QProgressBar;
    progressbarDownload->setObjectName("progressbarDownload"_L1);
    progressbarDownload->setRange(0, 100);
    progressbarDownload->setValue(0);
    progressbarDownload->setEnabled(false);

    QLabel* labelDownloadInfo = new QLabel(tr("0/1000"));
    labelDownloadInfo->setObjectName("labelDownloadInfo"_L1);
    labelDownloadInfo->setEnabled(false);

    QAction* actionUpdate = addAction(tr("&Update"));
    actionUpdate->setObjectName("actionUpdate"_L1);
    actionUpdate->setIcon(QIcon::fromTheme("download"_L1, QIcon(":/icons/actions/16/download"_L1)));
    actionUpdate->setIconText(tr("Update"));
    actionUpdate->setShortcut(Qt::CTRL | Qt::Key_U);
    actionUpdate->setStatusTip(tr("Update the MediathekView database"));
    actionUpdate->setToolTip(tr("Update the MediathekView database."));
    actionUpdate->setCheckable(true);

    QToolButton* buttonUpdate = new QToolButton;
    buttonUpdate->setObjectName("buttonUpdate"_L1);
    buttonUpdate->setDefaultAction(actionUpdate);
    buttonUpdate->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    buttonUpdate->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    QAction* actionCancel = addAction(tr("&Cancel"));
    actionCancel->setObjectName("actionCancel"_L1);
    actionCancel->setIcon(QIcon::fromTheme("remove"_L1, QIcon(":/icons/actions/16/remove"_L1)));
    actionCancel->setIconText(tr("Cancel"));
    actionCancel->setShortcut(Qt::CTRL | Qt::SHIFT | Qt::Key_U);
    actionCancel->setStatusTip(tr("Cancel the update of the MediathekView database"));
    actionCancel->setToolTip(tr("Cancel the update of the MediathekView database."));
    actionCancel->setEnabled(false);

    QToolButton* buttonCancel = new QToolButton;
    buttonCancel->setObjectName("buttonCancel"_L1);
    buttonCancel->setDefaultAction(actionCancel);
    buttonCancel->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    buttonCancel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    QGridLayout* layoutDatabaseUpdate = new QGridLayout;
    layoutDatabaseUpdate->setObjectName("layoutDatabaseUpdate"_L1);
    layoutDatabaseUpdate->addWidget(progressbarDownload, 0, 0, 1, 0);
    layoutDatabaseUpdate->addWidget(labelDownloadInfo, 1, 0, 1, 0);
    layoutDatabaseUpdate->addWidget(buttonUpdate, 2, 0);
    layoutDatabaseUpdate->addWidget(buttonCancel, 2, 1);

    QWidget* widgetDatabaseUpdate = new QWidget;
    widgetDatabaseUpdate->setObjectName("widgetDatabaseUpdate"_L1);
    widgetDatabaseUpdate->setLayout(layoutDatabaseUpdate);
    widgetDatabaseUpdate->setMinimumWidth(200);

    QWidgetAction* actionDatabaseUpdate  = new QWidgetAction(this);
    actionDatabaseUpdate->setObjectName("actionDatabaseUpdate"_L1);
    actionDatabaseUpdate->setDefaultWidget(widgetDatabaseUpdate);

    QAction* actionQuit = addAction(tr("&Quit"));
    actionQuit->setObjectName("actionQuit"_L1);
    actionQuit->setIcon(QIcon::fromTheme("application-exit"_L1, QIcon(":/icons/actions/16/application-exit"_L1)));
    actionQuit->setIconText(tr("Quit"));
    actionQuit->setShortcut(QKeySequence::Quit);
    actionQuit->setStatusTip(tr("Quit the application"));
    actionQuit->setToolTip(tr("Quit the application."));
    actionQuit->setMenuRole(QAction::QuitRole);

    QMenu* menuDatabaseUpdate = new QMenu(tr("Database Update"));
    menuDatabaseUpdate->setObjectName("menuDatabaseUpdate"_L1);
    menuDatabaseUpdate->addSection(tr("MediathekView Database"));
    menuDatabaseUpdate->addAction(actionDatabaseUpdate);

    QMenu* menuFile = menuBar()->addMenu(tr("&File"));
    menuFile->setObjectName("menuFile"_L1);
    menuFile->addMenu(menuDatabaseUpdate);
    menuFile->addSeparator();
    menuFile->addAction(actionQuit);

    QToolButton* buttonDatabaseUpdate = new QToolButton;
    buttonDatabaseUpdate->setObjectName("buttonDatabaseUpdate"_L1);
    buttonDatabaseUpdate->setText(tr("Update"));
    buttonDatabaseUpdate->setIcon(QIcon::fromTheme("download"_L1, QIcon(":/icons/actions/16/download"_L1)));
    buttonDatabaseUpdate->setMenu(menuDatabaseUpdate);
    buttonDatabaseUpdate->setPopupMode(QToolButton::InstantPopup);
    buttonDatabaseUpdate->setStatusTip(tr("Show the Database Update widget"));
    buttonDatabaseUpdate->setToolTip(tr("Show the Database Update widget."));

    QToolBar* toolbarFile = addToolBar(tr("File Toolbar"));
    toolbarFile->setObjectName("toolbarFile"_L1);
    toolbarFile->addWidget(buttonDatabaseUpdate);
    toolbarFile->addSeparator();
    toolbarFile->addAction(actionQuit);

    connect(actionUpdate, &QAction::toggled, progressbarDownload, &QProgressBar::setEnabled);
    connect(actionUpdate, &QAction::toggled, labelDownloadInfo, &QLabel::setEnabled);
    connect(actionUpdate, &QAction::toggled, actionCancel, &QAction::setEnabled);
    connect(actionCancel, &QAction::triggered, actionUpdate, &QAction::toggle);
    connect(actionQuit, &QAction::triggered, this, &MainWindow::close);

    // Channels menu & toolbar

    m_actionsChannels = new QActionGroup(this);
    m_actionsChannels->setObjectName("actionsChannels"_L1);
    m_actionsChannels->setExclusionPolicy(QActionGroup::ExclusionPolicy::None);

    for (const QStringList& channel : MediathekView::channels()) {
        // Channel: [0] Id, [1] Name, [2] Short Name, [3] Long Name, [4] Brief Description

        const QString& text = channel[3] != channel[2] ? tr("%1 (%2)").arg(channel[3], channel[2]) : channel[3];

        QAction* action = addAction(text);
        action->setObjectName("action_%1"_L1.arg(channel[0]));
        action->setIconText(channel[2]);
        action->setToolTip(tr("%1<br><strong>%2</strong><br>%3.").arg(channel[2], channel[3], channel[4]));
        action->setCheckable(true);
        action->setData(channel[0]);

        m_actionsChannels->addAction(action);
    }

    QMenu* menuChannels = menuBar()->addMenu(tr("&Channels"));
    menuChannels->setObjectName("menuChannels"_L1);
    menuChannels->addActions(m_actionsChannels->actions());

    QMenu* menuButtonToolbarChannelsMore = new QMenu(this);
    menuButtonToolbarChannelsMore->setObjectName("menuButtonToolbarChannelsMore"_L1);
    menuButtonToolbarChannelsMore->addActions(m_actionsChannels->actions());

    QToolButton* buttonToolbarChannelsMore = new QToolButton;
    buttonToolbarChannelsMore->setObjectName("buttonToolbarChannelsMore"_L1);
    buttonToolbarChannelsMore->setText(tr("more"));
    buttonToolbarChannelsMore->setMenu(menuButtonToolbarChannelsMore);
    buttonToolbarChannelsMore->setPopupMode(QToolButton::InstantPopup);

    QToolBar* toolbarChannels = addToolBar(tr("Channels Toolbar"));
    toolbarChannels->setObjectName("toolbarChannels"_L1);
    toolbarChannels->addActions(m_actionsChannels->actions());
    toolbarChannels->addWidget(buttonToolbarChannelsMore);

    // Filters menu & toolbar

    QxRangeSlider* sliderDurationMenu = new QxRangeSlider(Qt::Horizontal);
    sliderDurationMenu->setObjectName("sliderDurationMenu"_L1);
    sliderDurationMenu->setRange(0, 100);
    sliderDurationMenu->setValue(0);
    sliderDurationMenu->setStatusTip(tr("Select the duration of a media"));
    sliderDurationMenu->setToolTip(tr("Select the duration of a media."));

    QVBoxLayout* layoutSliderDurationMenu = new QVBoxLayout;
    layoutSliderDurationMenu->setObjectName("layoutSliderDurationMenu"_L1);
    layoutSliderDurationMenu->addWidget(sliderDurationMenu);

    QWidget* widgetSliderDurationMenu = new QWidget;
    widgetSliderDurationMenu->setObjectName("widgetSliderDurationMenu"_L1);
    widgetSliderDurationMenu->setLayout(layoutSliderDurationMenu);
    widgetSliderDurationMenu->setMinimumWidth(200);

    QWidgetAction* actionSliderDurationMenu = new QWidgetAction(this);
    actionSliderDurationMenu->setObjectName("actionSliderDurationMenu"_L1);
    actionSliderDurationMenu->setDefaultWidget(widgetSliderDurationMenu);
    addAction(actionSliderDurationMenu);

    QxRangeSlider* sliderPeriodMenu = new QxRangeSlider(Qt::Horizontal);
    sliderPeriodMenu->setObjectName("sliderPeriodMenu"_L1);
    sliderPeriodMenu->setRange(0, 100);
    sliderPeriodMenu->setValue(0);
    sliderPeriodMenu->setStatusTip(tr("Select the period of a media"));
    sliderPeriodMenu->setToolTip(tr("Select the period of a media."));

    QVBoxLayout* layoutSliderPeriodMenu = new QVBoxLayout;
    layoutSliderPeriodMenu->setObjectName("layoutSliderPeriodMenu"_L1);
    layoutSliderPeriodMenu->addWidget(sliderPeriodMenu);

    QWidget* widgetSliderPeriodMenu = new QWidget;
    widgetSliderPeriodMenu->setObjectName("widgetSliderPeriodMenu"_L1);
    widgetSliderPeriodMenu->setLayout(layoutSliderPeriodMenu);
    widgetSliderPeriodMenu->setMinimumWidth(200);

    QWidgetAction* actionSliderPeriodMenu = new QWidgetAction(this);
    actionSliderPeriodMenu->setObjectName("actionSliderPeriodMenu"_L1);
    actionSliderPeriodMenu->setDefaultWidget(widgetSliderPeriodMenu);
    addAction(actionSliderPeriodMenu);

    QAction* actionAudioDescription = addAction(tr("&Audio Description"));
    actionAudioDescription->setObjectName("actionAudioDescription"_L1);
    actionAudioDescription->setIcon(QIcon::fromTheme("new-audio-alarm"_L1, QIcon(":/icons/actions/16/new-audio-alarm"_L1)));
    actionAudioDescription->setIconText(tr("AD"));
    actionAudioDescription->setStatusTip(tr("Only media with audio description track"));
    actionAudioDescription->setToolTip(tr("Only media with audio description track."));
    actionAudioDescription->setCheckable(true);

    QAction* actionSignLanguage = addAction(tr("&Sign Language"));
    actionSignLanguage->setObjectName("actionSignLanguage"_L1);
    actionSignLanguage->setIcon(QIcon::fromTheme("languages"_L1, QIcon(":/icons/actions/16/languages"_L1)));
    actionSignLanguage->setIconText(tr("Sign"));
    actionSignLanguage->setStatusTip(tr("Only media with sign language"));
    actionSignLanguage->setToolTip(tr("Only media with sign language."));
    actionSignLanguage->setCheckable(true);

    QAction* actionTrailer = addAction(tr("&Trailer"));
    actionTrailer->setObjectName("actionTrailer"_L1);
    actionTrailer->setIcon(QIcon::fromTheme("folder-video"_L1, QIcon(":/icons/actions/16/folder-video"_L1)));
    actionTrailer->setIconText(tr("Trailer"));
    actionTrailer->setStatusTip(tr("Only trailer media"));
    actionTrailer->setToolTip(tr("Only trailer media."));
    actionTrailer->setCheckable(true);

    QAction* actionOriginalVersion = addAction(tr("&Original Version"));
    actionOriginalVersion->setObjectName("actionOriginalVersion"_L1);
    actionOriginalVersion->setIcon(QIcon::fromTheme("folder-video"_L1, QIcon(":/icons/actions/16/folder-video"_L1)));
    actionOriginalVersion->setIconText(tr("Original"));
    actionOriginalVersion->setStatusTip(tr("Only original versions"));
    actionOriginalVersion->setToolTip(tr("Only original versions."));
    actionOriginalVersion->setCheckable(true);

    QAction* actionLiveStreaming = addAction(tr("&Live Streaming"));
    actionLiveStreaming->setObjectName("actionLiveStreaming"_L1);
    actionLiveStreaming->setIcon(QIcon::fromTheme("network-wireless-hotspot"_L1, QIcon(":/icons/actions/16/network-wireless-hotspot"_L1)));
    actionLiveStreaming->setIconText(tr("Live"));
    actionLiveStreaming->setStatusTip(tr("Only live streamings"));
    actionLiveStreaming->setToolTip(tr("Only live streamings."));
    actionLiveStreaming->setCheckable(true);

    m_actionInvertChannels = addAction(tr("&Invert Channels"));
    m_actionInvertChannels->setObjectName("actionInvertChannels"_L1);
    m_actionInvertChannels->setIcon(QIcon::fromTheme("edit-select-invert"_L1, QIcon(":/icons/actions/16/edit-select-invert"_L1)));
    m_actionInvertChannels->setIconText(tr("Invert"));
    m_actionInvertChannels->setStatusTip(tr("Invert list of selected channels"));
    m_actionInvertChannels->setToolTip(tr("Invert list of selected channels."));
    m_actionInvertChannels->setCheckable(true);

    QMenu* menuFilters = menuBar()->addMenu(tr("&Filters"));
    menuFilters->setObjectName("menuFilters"_L1);
    menuFilters->addSection(tr("Duration"));
    menuFilters->addAction(actionSliderDurationMenu);
    menuFilters->addSection(tr("Period"));
    menuFilters->addAction(actionSliderPeriodMenu);
    menuFilters->addSection(tr("Media Types"));
    menuFilters->addAction(actionAudioDescription);
    menuFilters->addAction(actionSignLanguage);
    menuFilters->addAction(actionTrailer);
    menuFilters->addAction(actionOriginalVersion);
    menuFilters->addAction(actionLiveStreaming);
    menuFilters->addSection(tr("Channels"));
    menuFilters->addAction(m_actionInvertChannels);

    QxRangeSlider* sliderDurationToolbar = new QxRangeSlider(Qt::Horizontal);
    sliderDurationToolbar->setObjectName("sliderDurationToolbar"_L1);
    sliderDurationToolbar->setRange(0, 100);
    sliderDurationToolbar->setValue(0);
    sliderDurationToolbar->setStatusTip(tr("Select the duration of a media"));
    sliderDurationToolbar->setToolTip(tr("Select the duration of a media."));

    QVBoxLayout* layoutSliderDurationToolbar = new QVBoxLayout;
    layoutSliderDurationToolbar->setObjectName("layoutSliderDurationToolbar"_L1);
    layoutSliderDurationToolbar->addWidget(sliderDurationToolbar);

    QWidget* widgetSliderDurationToolbar = new QWidget;
    widgetSliderDurationToolbar->setObjectName("widgetSliderDurationToolbar"_L1);
    widgetSliderDurationToolbar->setLayout(layoutSliderDurationToolbar);
    widgetSliderDurationToolbar->setMaximumHeight(200);
    widgetSliderDurationToolbar->setMaximumWidth(200);

    QxRangeSlider* sliderPeriodToolbar = new QxRangeSlider(Qt::Horizontal);
    sliderPeriodToolbar->setObjectName("sliderPeriodToolbar"_L1);
    sliderPeriodToolbar->setRange(0, 100);
    sliderPeriodToolbar->setValue(0);
    sliderPeriodToolbar->setStatusTip(tr("Select the period of a media"));
    sliderPeriodToolbar->setToolTip(tr("Select the period of a media."));

    QVBoxLayout* layoutSliderPeriodToolbar = new QVBoxLayout;
    layoutSliderPeriodToolbar->setObjectName("layoutSliderPeriodToolbar"_L1);
    layoutSliderPeriodToolbar->addWidget(sliderPeriodToolbar);

    QWidget* widgetSliderPeriodToolbar = new QWidget;
    widgetSliderPeriodToolbar->setObjectName("widgetSliderPeriodToolbar"_L1);
    widgetSliderPeriodToolbar->setLayout(layoutSliderPeriodToolbar);
    widgetSliderPeriodToolbar->setMaximumHeight(200);
    widgetSliderPeriodToolbar->setMaximumWidth(200);

    QToolBar* toolbarFilters = addToolBar(tr("Filters Toolbar"));
    toolbarFilters->setObjectName("toolbarFilters"_L1);
    toolbarFilters->addWidget(widgetSliderDurationToolbar);
    toolbarFilters->addSeparator();
    toolbarFilters->addWidget(widgetSliderPeriodToolbar);
    toolbarFilters->addSeparator();
    toolbarFilters->addAction(actionAudioDescription);
    toolbarFilters->addAction(actionSignLanguage);
    toolbarFilters->addAction(actionTrailer);
    toolbarFilters->addAction(actionOriginalVersion);
    toolbarFilters->addAction(actionLiveStreaming);
    toolbarFilters->addSeparator();
    toolbarFilters->addAction(m_actionInvertChannels);

    m_actionInvertChannels->toggle();
    connect(m_actionInvertChannels, &QAction::toggled, this, &MainWindow::updateActionsChannels);
    m_actionInvertChannels->toggle();

    connect(sliderDurationMenu, &QxRangeSlider::valueChanged, sliderDurationToolbar, &QxRangeSlider::setValue);
    connect(sliderDurationToolbar, &QxRangeSlider::valueChanged, sliderDurationMenu, &QxRangeSlider::setValue);
    connect(toolbarFilters, &QToolBar::orientationChanged, sliderDurationToolbar, &QSlider::setOrientation);
    connect(sliderPeriodMenu, &QxRangeSlider::valueChanged, sliderPeriodToolbar, &QxRangeSlider::setValue);
    connect(sliderPeriodToolbar, &QxRangeSlider::valueChanged, sliderPeriodMenu, &QxRangeSlider::setValue);
    connect(toolbarFilters, &QToolBar::orientationChanged, sliderPeriodToolbar, &QSlider::setOrientation);

    // View menu & toolbar

    QAction* actionShowGrid = addAction(tr("Show &Grid"));
    actionShowGrid->setObjectName("actionShowGrid"_L1);
    actionShowGrid->setIcon(QIcon::fromTheme("show-grid"_L1, QIcon(":/icons/actions/16/show-grid"_L1)));
    actionShowGrid->setIconText(tr("Grid"));
    actionShowGrid->setStatusTip(tr("Show the grid"));
    actionShowGrid->setToolTip(tr("Show the grid."));
    actionShowGrid->setCheckable(true);
    actionShowGrid->setChecked(true);

    QAction* actionEnlargeFont = addAction(tr("&Enlarge Font"));
    actionEnlargeFont->setObjectName("actionEnlargeFont"_L1);
    actionEnlargeFont->setIcon(QIcon::fromTheme("zoom-in"_L1, QIcon(":/icons/actions/16/zoom-in"_L1)));
    actionEnlargeFont->setIconText(tr("Zoom In"));
    actionEnlargeFont->setShortcut(QKeySequence::ZoomIn);
    actionEnlargeFont->setStatusTip(tr("This increases the display font size"));
    actionEnlargeFont->setToolTip(tr("This increases the display font size."));

    QAction* actionShrinkFont = addAction(tr("S&hrink Font"));
    actionShrinkFont->setObjectName("actionShrinkFont"_L1);
    actionShrinkFont->setIcon(QIcon::fromTheme("zoom-out"_L1, QIcon(":/icons/actions/16/zoom-out"_L1)));
    actionShrinkFont->setIconText(tr("Zoom Out"));
    actionShrinkFont->setShortcut(QKeySequence::ZoomOut);
    actionShrinkFont->setStatusTip(tr("This decreases the display font size"));
    actionShrinkFont->setToolTip(tr("This decreases the display font size."));

    QAction* actionResetFontSize = addAction(tr("&Reset Font Size"));
    actionResetFontSize->setObjectName("actionResetFontSize"_L1);
    actionResetFontSize->setIcon(QIcon::fromTheme("zoom-original"_L1, QIcon(":/icons/actions/16/zoom-original"_L1)));
    actionResetFontSize->setIconText(tr("Zoom Original"));
    actionResetFontSize->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_0));
    actionResetFontSize->setStatusTip(tr("This resets the display font size"));
    actionResetFontSize->setToolTip(tr("This resets the display font size."));

    QAction* actionFullScreen = addAction(tr("F&ull Screen"));
    actionFullScreen->setObjectName("actionFullScreen"_L1);
    actionFullScreen->setIconText(tr("Full Screen"));
    actionFullScreen->setShortcuts({ QKeySequence(Qt::Key_F11), QKeySequence::FullScreen });
    actionFullScreen->setCheckable(true);

    actionFullScreen->toggle();
    connect(actionFullScreen, &QAction::toggled, [=](){
        if (!actionFullScreen->isChecked()) {
            actionFullScreen->setText(tr("F&ull Screen Mode"));
            actionFullScreen->setIcon(QIcon::fromTheme("view-fullscreen"_L1, QIcon(":/icons/actions/16/view-fullscreen"_L1)));
            actionFullScreen->setStatusTip(tr("Display the window in full screen"));
            actionFullScreen->setToolTip(tr("Display the window in full screen."));
        }
        else {
            actionFullScreen->setText(tr("Exit F&ull Screen Mode"));
            actionFullScreen->setIcon(QIcon::fromTheme("view-restore"_L1, QIcon(":/icons/actions/16/view-restore"_L1)));
            actionFullScreen->setStatusTip(tr("Exit the full screen mode"));
            actionFullScreen->setToolTip(tr("Exit the full screen mode."));
        }
    });
    actionFullScreen->toggle();

    QMenu* menuView = menuBar()->addMenu(tr("&View"));
    menuView->setObjectName("menuView"_L1);
    menuView->addAction(actionShowGrid);
    menuView->addSeparator();
    menuView->addAction(actionEnlargeFont);
    menuView->addAction(actionShrinkFont);
    menuView->addAction(actionResetFontSize);
    menuView->addSeparator();
    menuView->addAction(actionFullScreen);

    QxZoomButton* buttonZoomControl = new QxZoomButton;
    buttonZoomControl->setObjectName("buttonZoomControl"_L1);
    buttonZoomControl->setDefaultAction(actionResetFontSize);
    buttonZoomControl->setText(tr("%1%"));
    buttonZoomControl->setToolButtonStyle(Qt::ToolButtonTextOnly);

    QToolBar* toolbarView = addToolBar(tr("View Toolbar"));
    toolbarView->setObjectName("toolbarView"_L1);
    toolbarView->addAction(actionShowGrid);
    toolbarView->addSeparator();
    toolbarView->addAction(actionShrinkFont);
    toolbarView->addWidget(buttonZoomControl);
    toolbarView->addAction(actionEnlargeFont);
    toolbarView->addSeparator();
    toolbarView->addAction(actionFullScreen);

    connect(actionShowGrid, &QAction::toggled, m_mediathekViewView, &MediathekViewView::setShowGrid);
    connect(actionEnlargeFont, &QAction::triggered, buttonZoomControl, &QxZoomButton::zoomIn);
    connect(actionShrinkFont, &QAction::triggered, buttonZoomControl, &QxZoomButton::zoomOut);
    connect(actionResetFontSize, &QAction::triggered, buttonZoomControl, &QxZoomButton::resetZoom);
    connect(buttonZoomControl, &QxZoomButton::zoomFactorChanged, this, &MainWindow::applyZoomFactor);
    connect(actionFullScreen, &QAction::toggled, this, &MainWindow::toggleFullScreen);

    // Settings menu & toolbar

    m_actionSchemeTheme = addAction(tr("&Scheme && Theme"));
    m_actionSchemeTheme->setObjectName("actionSchemeTheme"_L1);
    m_actionSchemeTheme->setIcon(QIcon::fromTheme("color-mode-black-white"_L1, QIcon(":/icons/actions/16/color-mode-black-white"_L1)));
    m_actionSchemeTheme->setIconText(tr("Scheme && Theme"));
    m_actionSchemeTheme->setStatusTip(tr("Enable the theme & scheme"));
    m_actionSchemeTheme->setToolTip(tr("Enable the theme & scheme."));
    m_actionSchemeTheme->setCheckable(true);

    m_actionShowMenubar = addAction(tr("Show &Menubar"));
    m_actionShowMenubar->setObjectName("actionShowMenubar"_L1);
    m_actionShowMenubar->setIcon(QIcon::fromTheme("show-menu"_L1, QIcon(":/icons/actions/16/show-menu"_L1)));
    m_actionShowMenubar->setIconText(tr("Menubar"));
    m_actionShowMenubar->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_M));
    m_actionShowMenubar->setStatusTip(tr("Show the menubar"));
    m_actionShowMenubar->setToolTip(tr("Show the menubar."));
    m_actionShowMenubar->setCheckable(true);
    m_actionShowMenubar->setChecked(true);

    m_actionShowStatusbar = addAction(tr("Show St&atusbar"));
    m_actionShowStatusbar->setObjectName("actionShowStatusbar"_L1);
    m_actionShowStatusbar->setIcon(QIcon::fromTheme("show-menu"_L1, QIcon(":/icons/actions/16/show-menu"_L1)));
    m_actionShowStatusbar->setIconText(tr("Statusbar"));
    m_actionShowStatusbar->setStatusTip(tr("Show the statusbar"));
    m_actionShowStatusbar->setToolTip(tr("Show the statusbar."));
    m_actionShowStatusbar->setCheckable(true);
    m_actionShowStatusbar->setChecked(true);

    QAction* actionConfigureLanguage = addAction(tr("Configure &Language..."));
    actionConfigureLanguage->setObjectName("actionConfigureLanguage"_L1);
    actionConfigureLanguage->setIcon(QIcon::fromTheme("language-chooser"_L1, QIcon(":/icons/actions/16/language-chooser"_L1)));
    actionConfigureLanguage->setIconText(tr("Language"));
    actionConfigureLanguage->setStatusTip(tr("Configure the application's language"));
    actionConfigureLanguage->setToolTip(tr("Configure the application's language."));

    QAction* actionConfigureKeyboardShortcuts = addAction(tr("Configure &Keyboard Shortcuts..."));
    actionConfigureKeyboardShortcuts->setObjectName("actionConfigureKeyboardShortcuts"_L1);
    actionConfigureKeyboardShortcuts->setIcon(QIcon::fromTheme("configure-shortcuts"_L1, QIcon(":/icons/actions/16/configure-shortcuts"_L1)));
    actionConfigureKeyboardShortcuts->setIconText(tr("Shortcuts"));
    actionConfigureKeyboardShortcuts->setShortcut(QKeySequence(Qt::CTRL | Qt::ALT | Qt::Key_Comma));
    actionConfigureKeyboardShortcuts->setStatusTip(tr("Configure the application's keyboard shortcut assignments"));
    actionConfigureKeyboardShortcuts->setToolTip(tr("Configure the application's keyboard shortcut assignments."));

    QAction* actionConfigurePanels = addAction(tr("Configure &Panels..."));
    actionConfigurePanels->setObjectName("actionConfigurePanels"_L1);
    actionConfigurePanels->setIcon(QIcon::fromTheme("configure"_L1, QIcon(":/icons/actions/16/configure"_L1)));
    actionConfigurePanels->setIconText(tr("Panels"));
    actionConfigurePanels->setStatusTip(tr("Configure which items should appear in the panels"));
    actionConfigurePanels->setToolTip(tr("Configure which items should appear in the panels."));

    QAction* actionConfigureToolbars = addAction(tr("Configure &Toolbars..."));
    actionConfigureToolbars->setObjectName("actionConfigureToolbars"_L1);
    actionConfigureToolbars->setIcon(QIcon::fromTheme("configure-toolbars"_L1, QIcon(":/icons/actions/16/configure-toolbars"_L1)));
    actionConfigureToolbars->setIconText(tr("Toolbars"));
    actionConfigureToolbars->setStatusTip(tr("Configure which items should appear in the toolbars"));
    actionConfigureToolbars->setToolTip(tr("Configure which items should appear in the toolbars."));

    QAction* actionConfigure = addAction(tr("&Configure..."));
    actionConfigure->setObjectName("actionConfigure"_L1);
    actionConfigure->setIcon(QIcon::fromTheme("configure"_L1, QIcon(":/icons/actions/16/configure"_L1)));
    actionConfigure->setShortcut(QKeySequence::Preferences);
    actionConfigure->setStatusTip(tr("Configure various aspects of this application"));
    actionConfigure->setToolTip(tr("Configure various aspects of this application."));
    actionConfigure->setMenuRole(QAction::PreferencesRole);

    QMenu* menuSettings = menuBar()->addMenu(tr("&Settings"));
    menuSettings->setObjectName("menuSettings"_L1);

    QMenu* menuShowPanels = new QMenu(tr("Panels Shown"), menuSettings);
    menuShowPanels->setObjectName("menuShowPanels"_L1);

    QMenu* menuShowToolbars = new QMenu(tr("Toolbars Shown"), menuSettings);
    menuShowToolbars->setObjectName("menuShowToolbars"_L1);

    menuSettings->addAction(m_actionSchemeTheme);
    menuSettings->addSeparator();
    menuSettings->addAction(m_actionShowMenubar);
    menuSettings->addMenu(menuShowPanels);
    menuSettings->addMenu(menuShowToolbars);
    menuSettings->addAction(m_actionShowStatusbar);
    menuSettings->addSeparator();
    menuSettings->addAction(actionConfigureLanguage);
    menuSettings->addAction(actionConfigureKeyboardShortcuts);
    menuSettings->addAction(actionConfigurePanels);
    menuSettings->addAction(actionConfigureToolbars);
    menuSettings->addAction(actionConfigure);

    QToolButton* buttonConfigurePanels = new QToolButton;
    buttonConfigurePanels->setObjectName("buttonConfigurePanels"_L1);
    buttonConfigurePanels->setDefaultAction(actionConfigurePanels);
    buttonConfigurePanels->setMenu(menuShowPanels);
    buttonConfigurePanels->setPopupMode(QToolButton::MenuButtonPopup);

    QToolButton* buttonConfigureToolbars = new QToolButton;
    buttonConfigureToolbars->setObjectName("buttonConfigureToolbars"_L1);
    buttonConfigureToolbars->setDefaultAction(actionConfigureToolbars);
    buttonConfigureToolbars->setMenu(menuShowToolbars);
    buttonConfigureToolbars->setPopupMode(QToolButton::MenuButtonPopup);

    QToolBar* toolbarSettings = addToolBar(tr("Settings Toolbar"));
    toolbarSettings->setObjectName("toolbarSettings"_L1);
    toolbarSettings->addAction(m_actionSchemeTheme);
    toolbarSettings->addSeparator();
    toolbarSettings->addAction(m_actionShowMenubar);
    toolbarSettings->addWidget(buttonConfigurePanels);
    toolbarSettings->addWidget(buttonConfigureToolbars);
    toolbarSettings->addAction(m_actionShowStatusbar);
    toolbarSettings->addSeparator();
    toolbarSettings->addAction(actionConfigureLanguage);
    toolbarSettings->addAction(actionConfigureKeyboardShortcuts);
    toolbarSettings->addAction(actionConfigure);

    connect(m_actionShowMenubar, &QAction::toggled, menuBar(), &QMenuBar::setVisible);
    connect(m_actionShowStatusbar, &QAction::toggled, statusBar(), &QStatusBar::setVisible);
    connect(actionConfigureLanguage, &QAction::triggered, this, &MainWindow::showLanguageSettingsDialog);
    connect(actionConfigureKeyboardShortcuts, &QAction::triggered, this, &MainWindow::showShortcutSettingsDialog);
    connect(actionConfigurePanels, &QAction::triggered, this, &MainWindow::showPanelSettingsDialog);
    connect(actionConfigureToolbars, &QAction::triggered, this, &MainWindow::showToolbarSettingsDialog);
    connect(actionConfigure, &QAction::triggered, this, &MainWindow::showSettingsDialog);

    // Help menu & toolbar

    QAction* actionCopyComponents = addAction(tr("Copy &Components..."));
    actionCopyComponents->setObjectName("actionCopyComponents"_L1);
    actionCopyComponents->setIcon(QIcon::fromTheme("info"_L1, QIcon(":/icons/actions/16/info"_L1)));
    actionCopyComponents->setIconText(tr("Components"));
    actionCopyComponents->setStatusTip(tr("Copy application components to clipboard"));
    actionCopyComponents->setToolTip(tr("Copy application components to clipboard."));

    QAction* actionAbout = addAction(tr("&About %1").arg(QApplication::applicationName()));
    actionAbout->setObjectName("actionAbout"_L1);
    actionAbout->setIcon(QIcon::fromTheme("mediathekview-qt"_L1, QIcon(":/icons/apps/16/mediathekview-qt"_L1)));
    actionAbout->setIconText(tr("About"));
    actionAbout->setStatusTip(tr("Brief description of this application"));
    actionAbout->setToolTip(tr("Brief description of this application."));
    actionAbout->setMenuRole(QAction::AboutRole);

    QMenu* menuHelp = menuBar()->addMenu(tr("&Help"));
    menuHelp->setObjectName("menuHelp"_L1);
    menuHelp->addAction(actionCopyComponents);
    menuHelp->addSeparator();
    menuHelp->addAction(actionAbout);

    QToolBar* toolbarHelp = addToolBar(tr("Help Toolbar"));
    toolbarHelp->setObjectName("toolbarHelp"_L1);
    toolbarHelp->addAction(actionCopyComponents);
    toolbarHelp->addAction(actionAbout);

    connect(actionCopyComponents, &QAction::triggered, this, &MainWindow::showComponentsDialog);
    connect(actionAbout, &QAction::triggered, this, &MainWindow::showAboutDialog);

    // Show Toolbars menu

    menuShowToolbars->addSection(tr("Toolbars"));
    menuShowToolbars->addAction(toolbarFile->toggleViewAction());
    menuShowToolbars->addAction(toolbarChannels->toggleViewAction());
    menuShowToolbars->addAction(toolbarFilters->toggleViewAction());
    menuShowToolbars->addAction(toolbarView->toggleViewAction());
    menuShowToolbars->addAction(toolbarSettings->toggleViewAction());
    menuShowToolbars->addAction(toolbarHelp->toggleViewAction());

    // Channels panel

    QMenu* menuButtonPanelChannelsMore = new QMenu(this);
    menuButtonPanelChannelsMore->setObjectName("menuButtonPanelChannelsMore"_L1);
    menuButtonPanelChannelsMore->addActions(m_actionsChannels->actions());

    QToolButton* buttonPanelChannelsMore = new QToolButton;
    buttonPanelChannelsMore->setObjectName("buttonPanelChannelsMore"_L1);
    buttonPanelChannelsMore->setText(tr("more"));
    buttonPanelChannelsMore->setMenu(menuButtonPanelChannelsMore);
    buttonPanelChannelsMore->setPopupMode(QToolButton::InstantPopup);
    buttonPanelChannelsMore->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    QxToolGroup* panelChannelsGroupChannels = new QxToolGroup;
    panelChannelsGroupChannels->setObjectName("panelChannelsGroupChannels"_L1);
    panelChannelsGroupChannels->setTitle(tr("Channels"));
    panelChannelsGroupChannels->setType(QxToolGroup::NoBox);
    panelChannelsGroupChannels->addActions(m_actionsChannels->actions());
    panelChannelsGroupChannels->addWidget(buttonPanelChannelsMore);
    panelChannelsGroupChannels->setColumnCount(4);
    panelChannelsGroupChannels->setSpanning(true);

    QxToolPalette* panelChannels = new QxToolPalette(tr("Channels Panel"), this);
    panelChannels->setObjectName("panelChannels"_L1);
    panelChannels->addGroup(panelChannelsGroupChannels);
    panelChannels->setColumnCount(1);
    addDockWidget(Qt::RightDockWidgetArea, panelChannels);

    // Filters panel

    QxRangeSlider* sliderDurationPanel = new QxRangeSlider(Qt::Horizontal);
    sliderDurationPanel->setObjectName("sliderDurationPanel"_L1);
    sliderDurationPanel->setRange(0, 100);
    sliderDurationPanel->setValue(0);
    sliderDurationPanel->setStatusTip(tr("Select the duration of a media"));
    sliderDurationPanel->setToolTip(tr("Select the duration of a media."));

    QxToolGroup* panelFiltersGroupDuration = new QxToolGroup;
    panelFiltersGroupDuration->setObjectName("panelFiltersGroupDuration"_L1);
    panelFiltersGroupDuration->setTitle(tr("Duration"));
    panelFiltersGroupDuration->setType(QxToolGroup::GroupBox);
    panelFiltersGroupDuration->addWidget(sliderDurationPanel);

    QxRangeSlider* sliderPeriodPanel = new QxRangeSlider(Qt::Horizontal);
    sliderPeriodPanel->setObjectName("sliderPeriodPanel"_L1);
    sliderPeriodPanel->setRange(0, 100);
    sliderPeriodPanel->setValue(0);
    sliderPeriodPanel->setStatusTip(tr("Select the period of a media"));
    sliderPeriodPanel->setToolTip(tr("Select the period of a media."));

    QxToolGroup* panelFiltersGroupPeriod = new QxToolGroup;
    panelFiltersGroupPeriod->setObjectName("panelFiltersGroupPeriod"_L1);
    panelFiltersGroupPeriod->setTitle(tr("Period"));
    panelFiltersGroupPeriod->setType(QxToolGroup::GroupBox);
    panelFiltersGroupPeriod->addWidget(sliderPeriodPanel);

    QxToolGroup* panelFiltersGroupTypes = new QxToolGroup;
    panelFiltersGroupTypes->setObjectName("panelFiltersGroupTypes"_L1);
    panelFiltersGroupTypes->setTitle(tr("Types"));
    panelFiltersGroupTypes->setType(QxToolGroup::FrameBox);
    panelFiltersGroupTypes->addAction(actionAudioDescription);
    panelFiltersGroupTypes->addAction(actionSignLanguage);
    panelFiltersGroupTypes->addAction(actionTrailer);
    panelFiltersGroupTypes->addAction(actionOriginalVersion);
    panelFiltersGroupTypes->addAction(actionLiveStreaming);
    panelFiltersGroupTypes->addSeparator();
    panelFiltersGroupTypes->addAction(m_actionInvertChannels);

    QxToolPalette* panelFilters = new QxToolPalette(tr("Filters Panel"), this);
    panelFilters->setObjectName("panelFilters"_L1);
    panelFilters->addGroup(panelFiltersGroupDuration);
    panelFilters->addGroup(panelFiltersGroupPeriod);
    panelFilters->addGroup(panelFiltersGroupTypes);
    panelFilters->setColumnCount(2);
    panelFilters->setSpanning(true);
    addDockWidget(Qt::RightDockWidgetArea, panelFilters);

    connect(sliderDurationMenu, &QxRangeSlider::valueChanged, sliderDurationPanel, &QxRangeSlider::setValue);
    connect(sliderDurationPanel, &QxRangeSlider::valueChanged, sliderDurationMenu, &QxRangeSlider::setValue);
    connect(sliderPeriodMenu, &QxRangeSlider::valueChanged, sliderPeriodPanel, &QxRangeSlider::setValue);
    connect(sliderPeriodPanel, &QxRangeSlider::valueChanged, sliderPeriodMenu, &QxRangeSlider::setValue);

    // Database Update panel

    QProgressBar* progressbarDownloadPanel = new QProgressBar;
    progressbarDownloadPanel->setObjectName("progressbarDownloadPanel"_L1);
    progressbarDownloadPanel->setRange(0, 100);
    progressbarDownloadPanel->setValue(0);
    progressbarDownloadPanel->setEnabled(false);

    QxToolGroup* panelDatabaseUpdateGroupMediathekView = new QxToolGroup;
    panelDatabaseUpdateGroupMediathekView->setObjectName("panelDatabaseUpdateGroupMediathekView"_L1);
    panelDatabaseUpdateGroupMediathekView->setTitle(tr("MediathekView Database"));
    panelDatabaseUpdateGroupMediathekView->setType(QxToolGroup::NoBox);
    panelDatabaseUpdateGroupMediathekView->addWidget(progressbarDownloadPanel);
    panelDatabaseUpdateGroupMediathekView->setColumnCount(1);

    QxToolPalette* panelDatabaseUpdate = new QxToolPalette(tr("Database Update Panel"), this);
    panelDatabaseUpdate->setObjectName("panelDatabaseUpdate"_L1);
    panelDatabaseUpdate->addGroup(panelDatabaseUpdateGroupMediathekView);
    addDockWidget(Qt::BottomDockWidgetArea, panelDatabaseUpdate);

    connect(actionUpdate, &QAction::toggled, progressbarDownloadPanel, &QProgressBar::setEnabled);
    connect(progressbarDownload, &QProgressBar::valueChanged, progressbarDownloadPanel, &QProgressBar::setValue);

    // Show Panels menu

    menuShowPanels->addSection(tr("Panels"));
    menuShowPanels->addAction(panelChannels->toggleViewAction());
    menuShowPanels->addAction(panelFilters->toggleViewAction());
    menuShowPanels->addAction(panelDatabaseUpdate->toggleViewAction());

}


void MainWindow::updateActionsChannels()
{
    const bool checked = m_actionInvertChannels->isChecked();

    for (QAction* action : m_actionsChannels->actions()) {

        QFont font = action->font();
        font.setBold(checked && m_channelItemStyles.testFlag(ChannelItemStyle::Bold));
        font.setItalic(checked && m_channelItemStyles.testFlag(ChannelItemStyle::Italic));
        font.setStrikeOut(checked && m_channelItemStyles.testFlag(ChannelItemStyle::StrikeOut));
        action->setFont(font);

        const QString& statusTip = checked ? tr("None media of channel %1").arg(action->text()) : tr("All media of channel %1").arg(action->text());
        action->setStatusTip(statusTip);
    }
}


void MainWindow::closeEvent(QCloseEvent* event)
{
    const QMessageBox::StandardButton clicked = QxConfirmationBox::continueCancelWarning(this,
        tr("Quit the application"),
        tr("This will quit the application.\n"
           "Are you sure you want to continue?"),
        QString(),
        "Confirmations/Application/ApplicationQuit"_L1);

    if (clicked == QMessageBox::Cancel) {
        event->ignore();
        return;
    }

    // TODO
    if (isFullScreen())
        toggleFullScreen(false);

    saveSettings();
    event->accept();
}


void MainWindow::loadSettings()
{
    QSettings settings;

    const QByteArray geometry = settings.value("Application/Geometry"_L1, QByteArray()).toByteArray();
    if (!geometry.isEmpty())
        restoreGeometry(geometry);
    else
        resize(1280, 720);

    const QByteArray state = settings.value("Application/State"_L1, QByteArray()).toByteArray();
    if (!state.isEmpty())
        restoreState(state);

    const bool schemeTheme = settings.value("Application/SchemeTheme"_L1, false).toBool();
    m_actionSchemeTheme->setChecked(schemeTheme);

    const bool menubar = settings.value("Application/Menubar"_L1, true).toBool();
    m_actionShowMenubar->setChecked(menubar);

    const bool statusbar = settings.value("Application/Statusbar"_L1, true).toBool();
    m_actionShowStatusbar->setChecked(statusbar);
}


void MainWindow::saveSettings()
{
    QSettings settings;

    const QByteArray geometry = saveGeometry();
    settings.setValue("Application/Geometry"_L1, geometry);

    const QByteArray state = saveState();
    settings.setValue("Application/State"_L1, state);

    const bool schemeTheme = m_actionSchemeTheme->isChecked();
    settings.setValue("Application/SchemeTheme"_L1, schemeTheme);

    const bool menubar = m_actionShowMenubar->isChecked();
    settings.setValue("Application/Menubar"_L1, menubar);

    const bool statusbar = m_actionShowStatusbar->isChecked();
    settings.setValue("Application/Statusbar"_L1, statusbar);
}


void MainWindow::applyZoomFactor(const qreal factor)
{
    Q_UNUSED(factor)

}


void MainWindow::toggleFullScreen(const bool checked)
{
    if (checked)
        if (QApplication::platformName() == "xcb"_L1)
            setWindowState(windowState() | Qt::WindowFullScreen);
        else
            showFullScreen();
    else
        if (QApplication::platformName() == "xcb"_L1)
            setWindowState(windowState() & ~Qt::WindowFullScreen);
        else
            showNormal();
}


void MainWindow::showLanguageSettingsDialog()
{

}


void MainWindow::showShortcutSettingsDialog()
{

}


void MainWindow::showPanelSettingsDialog()
{

}


void MainWindow::showToolbarSettingsDialog()
{
    QxToolbarsDialog dialog(this);
    dialog.exec();
}


void MainWindow::showSettingsDialog()
{
    SettingsDialog dialog(this);
    dialog.exec();
}


void MainWindow::showComponentsDialog()
{
    QxComponentsDialog dialog(this);
    dialog.exec();
}


void MainWindow::showAboutDialog()
{
    QxAboutDialog dialog(this);
    dialog.setDescription(tr("Frontend tool for the MediathekView database."));
    dialog.addPage(new AboutDialogPageGeneral, tr("General"));
    dialog.addPage(new AboutDialogPageComponents, tr("Components"));
    dialog.addPage(new AboutDialogPageAuthors, tr("Authors"));
    dialog.addPage(new AboutDialogPageCredits, tr("Credits"));
    dialog.addPage(new AboutDialogPageLicense, tr("License"));
    dialog.setMinimumSize(854, 480);
    dialog.exec();
}
