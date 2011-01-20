function yui_editor_bidi() {
  for (var e in YAHOO.Drupal.editors) {
    var myEditor = YAHOO.Drupal.editors[e].editor;
    var config = YAHOO.Drupal.editors[e].config;
    var id = YAHOO.Drupal.editors[e].id;

    if (config.bidi == 1) {
      myEditor.on('toolbarLoaded', function () {
        var bidiConfig = {
          type: 'push', label: 'Switch to Right-to-Left', value: 'bidi'
        };
        myEditor.toolbar.addButtonToGroup(bidiConfig, 'plugins');

        myEditor.toolbar.on('bidiClick', function(ev) {
          var rtlHTML ='im inserted here';
          var sel =  this._getSelection();
          myEditor.execCommand('inserthtml', '<p dir="rtl">'+sel+'</p>');
        }, myEditor, true);
      });
    }
  }
}
YAHOO.Drupal.yui_editor_load.subscribe(yui_editor_bidi);