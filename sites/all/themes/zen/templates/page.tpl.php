<?php ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">

<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $classes; ?>">

<?php print $tabs; ?>
<div id="head" class="holder"><div id="head-inner" class="sector">

<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>

</div></div>

<div id="top-nav" class="holder"><div id="top-nav-inner" class="sector">
  <?php print theme(array('links__system_secondary_menu', 'links'), $secondary_links,
          array(
            'id' => 'secondary-menu',
            'class' => 'links clearfix',
          ),
          array(
            'text' => t('Secondary menu'),
            'level' => 'h2',
            'class' => 'element-invisible',
          ));
        ?>
		<?php include ('new-search.php'); ?>
                <div class="clearboth"></div>
</div></div>

<div id="banner" class="holder"><div id="banner-inner" class="sector"></div></div>

<div id="nav" class="holder"><div id="nav-in" class="sector"><?php print $navigation; ?></div></div><!-- nav -->

<div id="mid" class="holder"><div id="mid-inner" class="sector">
<?php print $content; ?>
</div></div>

<div id="btm" class="holder"><div id="btm-inner" class="sector"></div></div>

<?php include ('foot.php') ?>

  <?php print $page_closure; ?>

  <?php print $closure; ?>

</body>
</html>
