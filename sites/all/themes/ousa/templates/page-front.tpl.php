<?php ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">

<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <script type="text/javascript" src="/themes/ousa/js/jquery.hoverscroll-0.2.2.js"></script>
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

</head>
<body class="<?php print $classes; ?>">

<?php print $tabs; ?>
<div id="head" class="holder"><div id="head-inner" class="sector">
<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
    <div id="sharing_bar">
      <a target="_blank" href="https://api.twitter.com/1/statuses/user_timeline.rss?screen_name=orienteeringusa" title="OUSA RSS" class="chicklet" id="ck_rss"></a>
      <a target="_blank" href="https://youtube.com/orienteeringusa" title="Youtube" class="chicklet" id="ck_youtube"></a>
      <a target="_blank" href="https://twitter.com/orienteeringusa" title="Twitter" class="chicklet" id="ck_twitter"></a>
      <a target="_blank" href="https://www.facebook.com/OrienteeringUSA" title="Facebook" class="chicklet" id="ck_facebook"></a>
      <div class="clearboth"></div>
    </div><!-- sharing_bar-->
</div>
</div> <!--head headinner-->

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
<!--Go orienteering row-->
<div class="goorienteeringrow">
<div class="ousacolumn ousaone half">
<div class="ousacolumn ousaone-one">
<h2 class="title">Go Orienteering</h2>
<div class="imgcontainer"><a href="https://orienteeringusa.org/orienteers/on-foot/events/sanctioned-events-calendar">
<img src="/themes/ousa/images/front/national/<?php echo rand(1,17); ?>.jpg" />

<p class="icaption">National Orienteering Events</p></a>
</div>
<div class="imgcontainer"><a href="https://orienteeringusa.org/clubs/proximity">
<img src="/themes/ousa/images/front/find-a-club/<?php echo rand(1,12); ?>.jpg" />
<p class="icaption">Find a club near you</p></a>
</div>
</div>
</div>
<div class="ousacolumn ousatwo half">
<h2 class="h2red title nored">Upcoming Events</h2>
<div class="eventslist">
<a href="https://www.attackpoint.org/eventmap-simple.jsp" target="_blank" class="alleventslink">Complete event list</a>
<?php
$jsondata=file_get_contents("https://www.attackpoint.org/eventfeed.jsp?sports=1,6&levels=1,3,4,5,7,6&bounds=0.35156,-130.429687,57.515823,-42.539062&type=json&evurl=1");
$data=json_decode($jsondata);
$i = 0;
foreach ($data as $event) {
	 if ($i == 3) { break; }
	//print_r($event);
	$datefull=$event->prettydate;
	$datepieces = explode(" ", $datefull);
	?>
	<div class="eventrow">
<div class="datebox">
<div class="month"><?php echo $datepieces[0];?></div>
<div class="day"><?php echo intval($datepieces[1]); ?></div>
</div>
<div class="eventdetails">
<div class="eventname"><?php echo $event->name; ?></div>
<div class="eventloc"><?php echo $event->locname; ?></div>
<div class="eventlink"><a href="<?php echo $event->url; ?>" class="btn red linkevent" target="_blank">Event Details</a></div>
</div>
</div>
	<?php 	
	$i++;
	}
?>
</div>
<div class="clearboth"></div>
</div>
<!--End Go orienteering row-->
<!--Get Outside row-->
<div class="getoutsiderow">
<h2 class="title red">Get Outside and Explore</h2><?php print $content; ?>
<div class="clearboth"></div>
</div>
<!--End Get Outside row-->

<!--Feat video + Orienteering row-->
<div class="getoutsiderow videos">
<div class="ousacolumn ousaone half">
<?php print $home_featvideo; ?>
</div>
<div class="ousacolumn ousatwo half">

<?php print $home_introd; ?>
</div>
<div class="clearboth"></div>
</div>
<!--End Feat video + Orienteering row-->

<div class="ousacolumn ousaone">






<div class="clearboth"></div>
<?php include ('footcol.php') ; ?>
<?php print $home_sponsors; ?>

</div>
<div class="ousacolumn ousatwo new">

<?php print $sidebar_second; ?>




</div>


<div class="clearboth"></div>
<?php include ('copyright.php') ?>
</div></div>

<div id="btm" class="holder"><div id="btm-inner" class="sector">

</div></div>

<div class="clearboth"></div>


<?php include ('foot.php') ?>

<?php // print $page_closure; ?>

<?php print $closure; ?>

</body>
</html>
