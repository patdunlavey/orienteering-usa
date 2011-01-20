<?php
// $Id: table.inc,v 1.1.2.3 2008/11/21 22:54:27 jeffcd Exp $

/**
 * @file
 * Table plugin for the YUI Editor.
 */

function yui_editor_table_settings(&$form, &$profile) {
  $form['plugins']['table'] = array(
    '#type' => 'checkbox',
    '#title' => t('Table button'),
    '#default_value' => $profile['table'],
    '#description' => t('Add a button for creating tables. Note: This feature has only been tested in Firefox.'),
  );
}

function yui_editor_table_render(&$profile) {
  if (isset($profile['table']) && $profile['table'] == 1) {
    drupal_add_js(drupal_get_path('module', 'yui_editor') .'/plugins/table.js', 'module', 'footer');
    drupal_add_css(drupal_get_path('module', 'yui_editor') .'/plugins/table.css', 'module');
  }
}
