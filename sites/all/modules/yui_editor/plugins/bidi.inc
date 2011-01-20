<?php
function yui_editor_bidi_settings(&$form, &$profile) {
  $form['plugins']['bidi'] = array(
    '#type' => 'checkbox',
    '#title' => t('bidi buttons'),
    '#default_value' => $profile['bidi'],
    '#description' => t('Add a button fto control text directionality.'));
}

function yui_editor_bidi_render(&$profile) {
  if ($profile['bidi'] == 1) {
    drupal_add_js(drupal_get_path("module", "yui_editor") ."/plugins/bidi.js", 'module', 'footer');
    drupal_add_css(drupal_get_path("module", "yui_editor") ."/plugins/bidi.css", 'module');
  }  
}
