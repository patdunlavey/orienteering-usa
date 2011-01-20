<?php
// $Id: viewscarousel_style_plugin.inc,v 1.2.2.2 2009/11/05 20:29:50 robloach Exp $
/**
 * @file
 *  Provide the views carousel plugin object with default options and form.
 */

/**
  * Implementation of views_plugin_style().
  */
class viewscarousel_style_plugin extends views_plugin_style {
  function option_definition() {
    $options = parent::option_definition();
    $options['skin'] = array('default' => 'tango');
    $options['skin_path'] = array('default' => '');
    $options['vertical'] = array('default' => FALSE);
    $options['start'] = array('default' => '');
    $options['offset'] = array('default' => '');
    $options['scroll'] = array('default' => '');
    $options['visible'] = array('default' => NULL);
    $options['animation'] = array('default' => 'fast');
    $options['easing'] = array('default' => NULL);
    $options['auto'] = array('default' => 0);
    $options['wrap'] = array('default' => NULL);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['skin'] = array(
      '#type' => 'select',
      '#title' => t('Skin'),
      '#default_value' => $this->options['skin'],
      '#options' => array('ie7' => t('IE7'), 'tango' => t('Tango'), 'custom' => t('Custom')),
    );
    $form['skin_path'] = array(
      '#type' => 'textfield',
      '#title' => t('Custom skin path'),
      '#description' => t('The relative path to the custom CSS file defined for your carousel skin. Example: "sites/all/themes/mytheme/carousel.css". Leave blank to not automatically add a custom CSS file.'),
      '#default_value' => $this->options['skin_path'],
      '#process' => array('views_process_dependency'),
      '#dependency' => array('edit-style-options-skin' => array('custom')),
    );
    $form['vertical'] = array(
      '#type' => 'checkbox',
      '#title' => t('Vertical'),
      '#description' => t('Specifies wether the carousel appears in horizontal or vertical orientation. Changes the carousel from a left/right style to a up/down style carousel. Defaults to horizontal.'),
      '#default_value' => $this->options['vertical'],
    );
    $form['start'] = array(
      '#type' => 'textfield',
      '#title' => t('Start'),
      '#description' => t('The index of the item to start with.'),
      '#size' => 4,
      '#maxlength' => 4,
      '#default_value' => $this->options['start'],
    );
    $form['offset'] = array(
      '#type' => 'textfield',
      '#title' => t('Offset'),
      '#description' => t('The index of the first available item at initialisation.'),
      '#size' => 4,
      '#maxlength' => 4,
      '#default_value' => $this->options['offset'],
    );
    $form['scroll'] = array(
      '#type' => 'textfield',
      '#title' => t('Scroll'),
      '#description' => t('The number of items to scroll by'),
      '#size' => 4,
      '#maxlength' => 4,
      '#default_value' => $this->options['scroll'],
    );
    $form['visible'] = array(
      '#type' => 'checkbox',
      '#title' => t('Visibility'),
      '#default_value' => $this->options['visible'],
      '#description' => t('If set, the width/height of the items will be calculated and set depending on the width/height of the clipping, so that exactly that number of items will be visible.'),
    );
    $form['animation'] = array(
      '#type' => 'textfield',
      '#title' => t('Animation'),
      '#size' => 10,
      '#maxlength' => 10,
      '#default_value' => $this->options['animation'],
      '#description' => t('The speed of the scroll animation as string in jQuery terms ("slow"  or "fast") or milliseconds as integer (See <a href="http://docs.jquery.com/Effects/animate">jQuery Documentation</a>).'),
    );
    $form['easing'] = array(
      '#type' => 'textfield',
      '#title' => t('Easing'),
      '#size' => 10,
      '#maxlength' => 10,
      '#default_value' => $this->options['easing'],
      '#description' => t('The name of the easing effect that you want to use. See list of options in the <a href="http://docs.jquery.com/effects/animate">jQuery Documentations</a>.'),
    );
    $form['auto'] = array(
      '#type' => 'textfield',
      '#title' => t('Autoscrolling'),
      '#size' => 4,
      '#maxlength' => 4,
      '#default_value' => $this->options['auto'],
      '#description' => t('Specifies how many seconds to periodically autoscroll the content. If set to 0 (default) then autoscrolling is turned off.'),
    );
    $form['wrap'] = array(
      '#type' => 'select',
      '#title' => t('Wrap content'),
      '#default_value' => $this->options['wrap'],
      '#description' => t('Specifies whether to wrap at the first/last item (or both) and jump back to the start/end.'),
      '#options' => array(
        0 => t('Disabled'),
        'first' => t('First'),
        'last' => t('Last'),
        'both' => t('Both'),
        'circular' => t('Circular'),
      ),
    );
  } 
}
