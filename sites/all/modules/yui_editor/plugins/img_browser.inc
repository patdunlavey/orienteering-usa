<?php
/**
 * YUI Editor Image Browser Plugin - using IMCE
 *
 * @author Dave Hall <info@davehall.com.au>
 * @license GNU General Public License v2 (or later) http://www.gnu.org/licenses/gpl-2.0.html
 */

/**
 * Rendering hook
 *
 * @internal just adds some JS to the template - if IMCE is installed and available to the user
 *
 * @param array $profile Current user's profile data
 *
 * @return void
 */
function yui_editor_img_browser_render(&$profile) {
  $has_access = module_exists('imce') && function_exists('imce_access') && imce_access();
  $profile['img_browser'] = ($has_access ? $profile['img_browser'] : 0);
  if ($profile['img_browser'] == 1) {
    drupal_add_js(drupal_get_path("module", "yui_editor")."/plugins/img_browser.js", 'module', 'footer');
  }
}

/**
 * Settings hook to allow the inclusion IMCE
 *
 * @internal only rendered if IMCE is installed
 *
 * @param object $form the form being editted
 * @param object $profile The current user's profile data
 *
 * @return void
 */
function yui_editor_img_browser_settings(&$form, &$profile) {
  if ( !module_exists('imce') ) {
    return;
  }

  $form['plugins']['img_browser'] = array(
    '#type' => 'checkbox',
    '#title' => t('Image Browser'),
    '#default_value' => $profile['img_browser'],
    '#description' => t('Allow users to browse images directly from the editor for insertion into the editor. Note: IMCE module must be installed and configured for this to work. Works only with YUI 2.5.x at present.'));
}