// $Id: code_enable.js,v 1.1.2.5.2.1 2010/12/26 22:54:27 pdcarto Exp $

function yui_editor_code_enable() {
	for ( var e in YAHOO.Drupal.editors) {
		var myEditor = YAHOO.Drupal.editors[e].editor;
		var config = YAHOO.Drupal.editors[e].config;

		if (config.coder == 1) {
			myEditor.on('toolbarLoaded', function() {				
					delete myEditor.invalidHTML.button;
					delete myEditor.invalidHTML.form;
					delete myEditor.invalidHTML.iframe;
					delete myEditor.invalidHTML.input;
					delete myEditor.invalidHTML.link;
					delete myEditor.invalidHTML.script;
					delete myEditor.invalidHTML.select;
					delete myEditor.invalidHTML.style;
					delete myEditor.invalidHTML.textarea;
			}
			);
		}
	}
}

YAHOO.Drupal.yui_editor_load.subscribe(yui_editor_code_enable);
