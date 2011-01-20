<?php
// $Id: code_enable.inc,v 1.1.2.2.2.1 2010/12/26 22:54:27 pdcarto Exp $

/**
 * @file
 * Code_enable plugin for the YUI Editor.
 */

function yui_editor_code_enable_render() {
    drupal_add_js(drupal_get_path('module', 'yui_editor') .'/plugins/code_enable.js', 'module', 'footer');
}
