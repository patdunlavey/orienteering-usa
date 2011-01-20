/**
 * ICME image browser integration
 * 
 * @author Dave Hall <info@davehall.com.au>
 * 
 * @internal loosely based on the IMCE API docs - see http://ufku.com/drupal/imce/api
 * and the YUI editor img_upload plugin
 */

/**
 * @var object IMCEPopup Global reference to IMCE popup
 */
var imcePopup;

/**
 * IMCE integration bootstrapper
 * 
 * This function integrates IMCE into the YUI image insertion dialog box
 * 
 * @return void
 */
function yui_editor_img_browser() {
	var myEditor, config;
	for ( var e in YAHOO.Drupal.editors) {
		myEditor = YAHOO.Drupal.editors[e].editor;
		config = YAHOO.Drupal.editors[e].config;

		if (config.img_browser == 1) {
			yui_editor_img_browser_attach(myEditor);
		}
	}
};

/**
 * Attach the event listeners so the IMCE popup works
 * 
 * @param object rte YUI Editor to attach events to
 * 
 * @return void
 */
function yui_editor_img_browser_attach(rte) {
	rte.addListener('toolbarLoaded',function() {
		rte.toolbar.addListener('insertimageClick',function(o) {
			var imgPanel = new YAHOO.util.Element('yui-editor-panel');
			imgPanel.on('contentReady', function() {
				var Dom = YAHOO.util.Dom,
					urlInput = Dom.get('insertimage_url'),
					urlW = yui_editor_img_browser_pasreWidth(Dom.getStyle(urlInput, 'width')),
					imceTrigger = new YAHOO.widget.Button(
					{
						id : 'imceTrigger',
						label : 'Browse',
						container : urlInput.parentNode,
						onclick : {fn : yui_editor_img_browser_show}
					}),
					btnW = yui_editor_img_browser_pasreWidth(Dom.getStyle('imceTrigger', 'width'));

				Dom.setStyle(urlInput, 'width', (urlW.val - (btnW.val * 1.1)) + urlW.unit);
			});
		});
	});
};

/*
 * Parse a CSS width value
 * 
 * @param string w the width to parse
 * 
 * @return object the value (val) and the unit of measure (unit) 
 */
function yui_editor_img_browser_pasreWidth(w) {
	var l = w.length,
		c = l - 2,
		r = {val: 0, unit: ''};
	return {val : w.substr(0, c), unit : w.substr(c, 2)};
};

/**
 * onClick handler which displays the IMCE popup window
 * 
 * @return void
 */
function yui_editor_img_browser_show() {
	if (typeof imcePopup == 'undefined' || imcePopup.closed) {
		imcePopup = window.open('?q=imce', '',
				'width=760,height=560,resizable=1');

		imcePopup['imceOnLoad'] = function(win) {
			win.imce.setSendTo('Update fields', yui_editor_img_browser_finish);
		};
	}
	imcePopup.focus();
};

/**
 * Event handler for populating the YUI image insert dialog
 * 
 * @param object file the selected file
 * @param object win the popup window
 * 
 * @return void
 */
function yui_editor_img_browser_finish(file, win) {
	var Dom = YAHOO.util.Dom;
	Dom.get('insertimage_url').value = file.url;
	Dom.get('insertimage_width').value = file.width;
	Dom.get('insertimage_height').value = file.height;

	win.blur();
};

YAHOO.Drupal.yui_editor_load.subscribe(yui_editor_img_browser);