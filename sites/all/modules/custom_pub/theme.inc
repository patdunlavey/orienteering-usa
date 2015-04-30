<?php
/**
 * @file
 *   Theme functions for Custom publishing options
 */
function theme_custom_pub_edit_form($form) {
  $type = $form['type']['#value'];  
  $head = array(
    t('Label'),
    t('Machine Name'),
    t('Node Types'),
    array('data' => '', 'class' => 'close-cusotm-pub-table'),
  );
  
  $rows = array(
    array(
      drupal_render($form['state']),
      $type['type'] . drupal_render($form['stateh']),
      drupal_render($form['node_types']),
      drupal_render($form),
    ),
  );

  $title = t('Edit @type option', array('@type' => $type['name']));
  return theme('table', $head, $rows, NULL, $title);
}
