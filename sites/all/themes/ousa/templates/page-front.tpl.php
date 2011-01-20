<?php ?>
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
<div id="sharing_bar">
<a target="_blank" href="https://twitter.com/statuses/user_timeline/182156990.rss" title="OUSA RSS" class="chicklet" id="ck_rss"></a>
<a target="_blank" href="http://youtube.com/orienteeringusa" title="Youtube" class="chicklet" id="ck_youtube"></a>
<a target="_blank" href="http://twitter.com/orienteeringusa" title="Twitter" class="chicklet" id="ck_twitter"></a>
<div class="clearboth"></div>
</div>
</div></div> <!--head headinner-->

<div id="top-nav" class="holder"><div id="top-nav-inner" class="sector">
 <div id="top-nav-menu"><?php print theme(array('links__system_secondary_menu', 'links'), $secondary_links,
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

<div id="banner" class="holder"><div id="banner-inner" class="sector"><?php print $home_banner; ?></div></div>

<div id="nav" class="holder"><div id="nav-in" class="sector"><?php print $navigation; ?></div></div><!-- nav -->

<div id="mid" class="holder"><div id="mid-inner" class="sector">

<div class="ousacolumn ousaone">
<div class="ousacolumn ousaone-one"><?php print $sidebar_first; ?></div>
<div class="ousacolumn ousaone-two"><h2 class="h2red">Get Started</h2><?php print $content; ?></div>
<div class="ousacolumn ousaone-three"><?php print $home_photo_slider; ?></div>
<?php print $home_sponsors; ?>

<div class="clearboth"></div>
<?php include ('footcol.php') ; ?>

</div>
<div class="ousacolumn ousatwo">

<?php print $sidebar_second; ?>

<div id="block-block-1" class="block block-block region-odd even region-count-1 count-2 with-block-editing">
      <h2 class="title">Featured News</h2>
  
  <div class="content">

    <ul id="twitter_update_list"></ul>
  </div>
</div>


<?php include ('copyright.php') ?>


</div>


<div class="clearboth"></div>

</div></div>

<div id="btm" class="holder"><div id="btm-inner" class="sector">

</div></div>

<div class="clearboth"></div>

<?php include ('foot.php') ?>

<?php print $page_closure; ?>

<?php print $closure; ?>

</body>
</html>
