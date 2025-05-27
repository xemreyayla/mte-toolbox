function Controller() {
    installer.autoRejectMessageBoxes();
    installer.setMessageBoxAutomaticAnswer("OverwriteTargetDirectory", QMessageBox.Yes);
}

Controller.prototype.IntroductionPageCallback = function() {
    gui.clickButton(buttons.NextButton);
}

Controller.prototype.CredentialsPageCallback = function() {
    gui.clickButton(buttons.NextButton);
}

Controller.prototype.ObligationsPageCallback = function() {
    gui.clickButton(buttons.NextButton);
}

Controller.prototype.ComponentSelectionPageCallback = function() {
    // Qt 6.8.3 GCC64 kurulumunu seçiyoruz
    var widget = gui.currentPageWidget();
    widget.deselectAll();
    widget.selectComponent("qt.qt6.${QT_VERSION}.gcc_64");
    gui.clickButton(buttons.NextButton);
}

Controller.prototype.InstallationFinishedPageCallback = function() {
    gui.clickButton(buttons.FinishButton);
}
