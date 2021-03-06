<?php global $user; ?>
<?php $uri = explode('/', $_SERVER['REQUEST_URI']); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">

<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <!-- HORIZONTAL Scroll - Photo  -->
<script type="text/javascript" charset="utf-8">
        $(function(){
  var div = $('div.sc_menu'),
               ul = $('ul.sc_menu'),
               ulPadding = 10;
  var divWidth = div.width();
  div.css({overflow: 'hidden'});
  var lastLi = ul.find('li:last-child');
  div.mousemove(function(e){
	var ulWidth = lastLi[0].offsetLeft + lastLi.outerWidth() + ulPadding;
    var left = (e.pageX - div.offset().left) * (ulWidth-divWidth) / divWidth;
    div.scrollLeft(left);
  });
});
    </script>
<!-- HORIZONTAL Scroll - Photo End -->

<!-- VERTICAL Scroll -->

	<script type="text/javascript">
		$(document).ready(function() {
		$('#twitter_update_list').hoverscroll();
	});
	</script>

<script type="text/javascript" src="/sites/all/themes/ousa/js/jquery.hoverscroll-0.2.2.js"></script>
</head>
<body class="<?php print $classes; ?>">

<?php print $tabs; ?>
<div id="head" class="holder"><div id="head-inner" class="sector">
<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
</div></div>

<div id="top-nav" class="holder"><div id="top-nav-inner" class="sector">
 <div id="top-nav-menu"> <?php print theme(array('links__system_secondary_menu', 'links'), $secondary_links,
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
		<?php include ('new-search.php'); ?></div><!-- top-nav-menu -->
        <div class="clearboth"></div>
</div></div>

<div id="banner" class="holder"><div id="banner-inner" class="sector"><?php print $content_top; ?></div></div>

<div id="nav" class="holder"><div id="nav-in" class="sector"><?php print $navigation; ?></div></div><!-- nav -->

<?php if ($uri[1] == 'node') : ?>
<style>.widget-preview {display:none!important}</style>

<div id="mid" class="holder"><div id="mid-inner" class="sector">

<div class="interior-page noder">
<?php print $breadcrumb; ?>
<div class="interior-page-in noder">
<h1 class="title"><?php print $title; ?></h1>
<?php print $content; ?>
<?php print $content_bottom; ?>
</div></div>

</div></div>

<?php else : ?>

<div id="mid" class="holder"><div id="mid-inner" class="sector">

<div class="ousacolumn ousaone">
<div class="interior-page">
<div class="breadcrumb"> <a href="/">Home</a> > <a href="/documents">Documents</a> > <?php print $title; ?> </div>
<div class="interior-page-in">
<h1 class="title"><?php print $title; ?></h1>
<?php print $content; ?>
<?php print $content_bottom; ?>
</div></div>
<div class="clearboth"></div>
<?php print $home_sponsors; ?>
<div class="clearboth"></div>
<?php include ('footcol.php') ; ?>

</div>
<div class="ousacolumn ousatwo">

<?php print $sidebar_second; ?>

<?php include ('copyright.php') ?>

</div>

<div class="clearboth"></div>

</div></div>

<div id="btm" class="holder"><div id="btm-inner" class="sector">

</div></div>

<div class="clearboth"></div>

<?php include ('foot.php') ?>

<?php endif; ?>

<?php // print $page_closure; ?>
<?php print $closure; ?>

</body>
</html>
