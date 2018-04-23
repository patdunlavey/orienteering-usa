var cpi_rand, cpi_cpcache;
var cpi = {};

cpi.idealthumbsize = 150;
cpi.colspacing = 10;
cpi.captionheight = 50;
cpi.singlecaptionheight = 35;
cpi.rand = Math.random();
cpi.cpcache = 'http://content' + Math.ceil(cpi.rand * 9) + '.cpcache.com';
//cpi.webstore = 'http://0.0.0.0:3000';
cpi.webstore = 'http://widgets.cafepress.com';
cpi.affiliate = '';

cpi.redirect = function(link){
  var url = link.split('?');
  var poke = 'http://widgets.cafepress.com/poke/javascript?CMP=swidget_logo&utm_campaign=swidget&utm_medium=seo&utm_source=image_click_logo' + url[1];
  cpiJQ('body').append('<iframe style="width: 0px; height: 0px; overflow: hidden; display: none;" src="javascript:false;" scrollbar="no" class="cafepress_loader" name="cafepress_loader" id="cafepress_loader" frameborder="0" scrolling="no"></iframe>');
  cpiJQ('iframe#cafepress_loader').load(function(){
    try {
      window.top.location = link;
    } catch (e) {
      window.location = link;
    }
    
  });
  cpiJQ('iframe#cafepress_loader').attr('src', poke);
};

cpi.queue = function() {

	if (typeof(window.cpi_queued) == 'undefined') {
		window.cpi_queued = 1;

		cpi.applets = {};
		cpi.appletqueue = [];

		cpiJQ('.cpi').each(function() {

			cpi.me = {};

			cpi.me.id = '#' + cpiJQ(this).attr('id');
			cpi.me.seeallurl = 'http://www.cafepress.com/';
			cpi.me.source = cpiJQ(this).attr('source');
			cpi.applets[cpi.me.id] = cpi.me;
			cpi.appletqueue.push(cpi.me.id);
			cpi.me.affiliate = cpiJQ(this).attr('affiliate') || '';
			cpi.me.tracking = cpiJQ(this).attr('tracking') || '';
			cpi.me.color = ' cpi-' + cpiJQ(this).attr('color');

			cpiJQ(this).css('display','none');
			cpiJQ(cpi.me.id + ' a').css({'position':'absolute','left':'0'});
			cpiJQ(cpi.me.id + ' a').css('font-size','10px');
			cpiJQ(this).append('<div class="cpi-barbg' + cpi.me.color + '"></div>');
			var barbg = cpiJQ(this).find('.cpi-barbg');
			
			barbg.append('<div class="cpi-barleft" title="Find custom gifts at CafePress"></div>');
			barbg.append('<div class="cpi-seeall" title="See all products" appletid="' + cpi.me.id + '"></div>');
			barbg.append('<div class="cpi-settings" appletid="' + cpi.me.id + '"></div>');
			barbg.append('<div class="cpi-bar"></div>');
			
			cpiJQ(this).append('<div class="cpi-window"></div>');
			cpiJQ(cpi.me.id + ' .cpi-window').append('<div class="cpi-canvas"></div>');
			cpiJQ(cpi.me.id + ' .cpi-window').append('<div appletid="' + cpi.me.id + '" class="cpi-pageless"></div>');
			cpiJQ(cpi.me.id + ' .cpi-window').append('<div appletid="' + cpi.me.id + '" class="cpi-pagemore"></div>');
			cpiJQ(this).append('<div class="cpi-settings-overlay"><div class="cpi-settings-overlay-title">Share This Widget</div><div appletid="' + cpi.me.id + '" class="cpi-settings-overlay-close">x</div>To use this widget on your own site, just copy and paste this HTML:<br/><textarea appletid="' + cpi.me.id + '" class="cpi-settings-html" readonly="true" style="width:100%;height:50px;position:relative;"/></div>');
			cpiJQ(cpi.me.id + ' .cpi-settings-html').val('<div color="' + cpiJQ(this).attr('color') + '" affiliate="' + cpi.me.affiliate + '" source="' + cpiJQ(this).attr('source') + '" class="' + cpiJQ(this).attr('class') + '" id="' + cpiJQ(this).attr('id') + '" height="' + cpiJQ(this).attr('height') + '" width="' + cpiJQ(this).attr('width') + '">Make&nbsp;<a href="http://www.cafepress.com/make/">Custom Gifts</a>&nbsp;at CafePress</div><script type="text/javascript" src="' + cpi.cpcache + '/marketplace/widgets/javascripts/widget.js"></script>');


			cpi.me.height = cpiJQ(this).attr('height');
			if (cpi.me.height < 200) {
				cpi.me.height = 200;
			} else if (cpi.me.height > 2000) {
				cpi.me.height = 2000;
			}
			cpi.me.width = cpiJQ(this).attr('width');
			if (cpi.me.width < 200) {
				cpi.me.width = 200;
			} else if (cpi.me.width > 2000) {
				cpi.me.width = 2000;
			}

			if (cpiJQ.browser.msie) {
				cpiJQ(cpi.me.id + ' .cpi-bar').css('width',(cpi.me.width - 144) + 'px');
				cpiJQ(cpi.me.id + ' .cpi-canvas').css('height',(cpi.me.height - 42) + 'px');
				cpiJQ(cpi.me.id + ' .cpi-window').css('height',(cpi.me.height - 42) + 'px');
			}

			cpiJQ(this).css('height',cpi.me.height + 'px');
			cpiJQ(this).css('width',cpi.me.width + 'px');
			cpiJQ(this).css('display','block');

			if (cpi.me.height > 600) {
				cpi.me.canvasheight = cpi.me.height - 70;
			} else {
				cpi.me.canvasheight = cpi.me.height - 40;
			}
			cpi.me.canvaswidth = cpi.me.width - 60;
			cpi.me.colspacing = cpi.colspacing;

			var cpi_rowcount = cpi.me.canvasheight / (cpi.idealthumbsize + cpi.captionheight);
			var cpi_colcount = cpi.me.canvaswidth / (cpi.idealthumbsize + cpi.me.colspacing);
			cpi.me.shortside = (cpi_rowcount < cpi_colcount) ? "height" : "width";
			cpi.me.shortsize = (cpi_rowcount < cpi_colcount) ? Math.round(cpi_rowcount) : Math.round(cpi_colcount);

			if (cpi.me.shortsize <= 0) {
				cpi.me.shortsize = 1;
			}

			if (cpi.me.shortside == "height") {
				cpi.me.thumbsize = Math.floor(cpi.me.canvasheight / cpi.me.shortsize) - cpi.captionheight;
				cpi.me.rowcount = cpi.me.shortsize;
				cpi.me.colcount = Math.floor(cpi.me.canvaswidth / (cpi.me.thumbsize + cpi.me.colspacing));
				if (cpi.me.colcount === 0) { cpi.me.colcount++; }

				//if the perspective calls for an additional row or column, add it
				if (cpi.me.canvaswidth % (cpi.me.thumbsize + cpi.colspacing) > cpi.me.thumbsize * 0.8) {
					cpi.me.colcount++;
					cpi.me.thumbsize = Math.floor(cpi.me.canvaswidth / cpi.me.colcount) - cpi.colspacing;
				}

			} else {
				cpi.me.thumbsize = Math.floor(cpi.me.canvaswidth / cpi.me.shortsize) - cpi.me.colspacing;
				cpi.me.colcount = cpi.me.shortsize;
				cpi.me.rowcount = Math.floor(cpi.me.canvasheight / (cpi.me.thumbsize + cpi.captionheight));
				if (cpi.me.rowcount === 0) { cpi.me.rowcount++; }

				//if the perspective calls for an additional row or column, add it
				if ((cpi.me.canvasheight % (cpi.me.thumbsize + cpi.captionheight)) > cpi.me.thumbsize * 0.8) {
					cpi.me.rowcount++;
					cpi.me.thumbsize = Math.floor(cpi.me.canvasheight / cpi.me.rowcount) - cpi.captionheight;
				}
			}

			cpi.me.colspacing = (cpi.me.canvaswidth / cpi.me.colcount) - cpi.me.thumbsize;
			cpi.me.cellheight = cpi.me.thumbsize + cpi.captionheight;
			cpi.me.cellwidth = cpi.me.thumbsize + cpi.me.colspacing;
			cpi.me.leftpad = 30;
			cpi.me.toppad = Math.floor((cpi.me.canvasheight - (cpi.me.rowcount * cpi.me.cellheight)) / 2);

			cpi.me.issquare = (cpi.me.width == cpi.me.height) ? true : false;
			cpi.me.issingle = ((cpi.me.colcount == 1) && (cpi.me.rowcount == 1)) ? true : false;
			if (cpi.me.issquare && cpi.me.issingle) {
				cpi.me.thumbsize = cpi.me.width - 36;
				cpi.me.cellwidth = cpi.me.thumbsize;
				cpi.me.cellheight = cpi.me.thumbsize;
			}

			cpiJQ(cpi.me.id + ' .cpi-pagemore').css('height',cpi.me.canvasheight);
			cpiJQ(cpi.me.id + ' .cpi-pageless').css('height',cpi.me.canvasheight);
			cpiJQ(cpi.me.id + ' .cpi-pagemore').css('width',cpi.me.leftpad);
			cpiJQ(cpi.me.id + ' .cpi-pageless').css('width',cpi.me.leftpad);

			cpi.me.pageno = 0;
			cpi.me.counter = 0;
			cpi.me.currentpage = 1;
			cpi.me.lastproduct = 0;
			cpi.me.pagesloaded = 0;
			cpi.me.lastpage = 100;

			if (cpiJQ(cpi.me.id).attr('animate') == 'false') {
				cpi.me.disableanimation = true;
			}

		});

		cpi.addpages();

		cpiJQ('.cpi-pagemore').bind('click',function(index) {
			if(cpi.me.currentpage < cpi.me.lastpage){
				cpi.me = cpi.applets[cpiJQ(this).attr('appletid')];
				cpi.me.currentpage++;
				if (cpiJQ(cpi.me.id + ' .cpi-pagemore').css('opacity') > 0.5) {
					if (cpi.me.pagesloaded < cpi.me.currentpage) {
						cpi.appletqueue.push(cpi.me.id);
						cpi.addpages();
					}
					if (cpi.me.disableanimation) { jQuery.fx.off = true; }
					cpiJQ(cpi.me.id + ' .cpi-canvas').stop(true).animate({left: ((cpi.me.currentpage - 1) * cpi.me.width * -1) },300 + (100 * cpi.me.colcount),function() {
						cpi.checkvals(cpi.me);
					});
					if (cpi.me.disableanimation) { jQuery.fx.off = false; }
					cpi.setbuttons(cpi.me);
					if (cpiJQ(cpi.me.id).attr('jumptotop') == "true") { window.scrollTo(0, 0); }
				}
			}
		});

		cpiJQ('.cpi-pageless').bind('click',function(index) {
			if(cpi.me.currentpage > 1){
				cpi.me = cpi.applets[cpiJQ(this).attr('appletid')];
				cpi.me.currentpage--;
				if (cpiJQ(cpi.me.id + ' .cpi-pageless').css('opacity') > 0.5) {
					if (cpi.me.currentpage < 1) {
						cpi.me.currentpage = 1;
					} else {
						if (cpi.me.disableanimation) { jQuery.fx.off = true; }
						cpiJQ(cpi.me.id + ' .cpi-canvas').stop(true).animate({left: ((cpi.me.currentpage - 1) * cpi.me.width * -1) },300 + (100 * cpi.me.colcount),function() {
							cpi.checkvals(cpi.me);
						});
						if (cpi.me.disableanimation) { jQuery.fx.off = false; }
					}
				}
				cpi.setbuttons(cpi.me);
				if (cpiJQ(cpi.me.id).attr('jumptotop') == "true") { window.scrollTo(0, 0); }
			}
		});
		
		cpiJQ('.cpi-cell').live('click',function(event) {
			var cpi_linkurl = cpiJQ(this).attr('linkurl');
			//window.location.href = cpi_linkurl;
      cpi.redirect(cpi_linkurl);
		});

		cpiJQ('.cpi-screenright').click(function(index) {
			cpi.me = cpi.applets[cpiJQ(this).attr('appletid')];
			cpiJQ(cpi.me.id + ' .cpi-pagemore').click();
		});
		cpiJQ('.cpi-screenleft').click(function(index) {
			cpi.me = cpi.applets[cpiJQ(this).attr('appletid')];
			cpiJQ(cpi.me.id + ' .cpi-pageless').click();
		});
		cpiJQ('.cpi-linkmore').bind('click',function(event) {
			cpi.me = cpi.applets[cpiJQ(this).attr('appletid')];
			cpiJQ(cpi.me.id + ' .cpi-pagemore').click();
		});
		cpiJQ('.cpi-linkless').bind('click',function(event) {
			cpi.me = cpi.applets[cpiJQ(this).attr('appletid')];
			cpiJQ(cpi.me.id + ' .cpi-pageless').click();
		});
		cpiJQ('.cpi-barleft').bind('click',function(event) {
      var linky = 'http://www.cafepress.com?';
      if (cpi.me.affiliate != '')
        linky = linky + '&aid=' + cpi.me.tracking;
			//window.location.href = linky;
      cpi.redirect(linky);
		});
		cpiJQ('.cpi-seeall').bind('click',function(event) {
			cpi.doseeall(cpi.applets[cpiJQ(this).attr('appletid')]);
		});
		cpiJQ('.cpi-settings').bind('click',function(event) {
			cpi.me = cpi.applets[cpiJQ(this).attr('appletid')];
			cpiJQ(cpi.me.id + ' .cpi-settings-overlay').slideToggle(300);
		});
		cpiJQ('.cpi-settings-overlay-close').bind('click',function(event) {
			cpi.me = cpi.applets[cpiJQ(this).attr('appletid')];
			cpiJQ(cpi.me.id + ' .cpi-settings-overlay').slideToggle(300);
		});
		cpiJQ('.cpi-settings-html').bind('click',function(event) {
			cpi.me = cpi.applets[cpiJQ(this).attr('appletid')];
			cpiJQ(cpi.me.id + ' .cpi-settings-html').focus();
			cpiJQ(cpi.me.id + ' .cpi-settings-html').select();
		});

    // create iframe page loader here

	}
};

cpi.setbuttons = function(applet) {
	cpi.me = applet;
	if ((cpi.me.currentpage == 1) && (cpi.me.lastpage == 1)) {
			cpiJQ(cpi.me.id + ' .cpi-pageless').css('display','none');
			cpiJQ(cpi.me.id + ' .cpi-pagemore').css('display','none');
	} else {
		if (cpi.me.currentpage <= 1) {
			cpiJQ(cpi.me.id + ' .cpi-pageless').stop(true).fadeTo(300,0.2);
			cpiJQ(cpi.me.id + ' .cpi-pageless').css('cursor','default');
		} else {
			cpiJQ(cpi.me.id + ' .cpi-pageless').stop(true).fadeTo(300,1);
			cpiJQ(cpi.me.id + ' .cpi-pageless').css('cursor','pointer');
		}
		if (cpi.me.currentpage >= cpi.me.lastpage) {
			cpiJQ(cpi.me.id + ' .cpi-pagemore').stop(true).fadeTo(300,0.2);
			cpiJQ(cpi.me.id + ' .cpi-pagemore').css('cursor','default');
		} else {
			cpiJQ(cpi.me.id + ' .cpi-pagemore').stop(true).fadeTo(300,1);
			cpiJQ(cpi.me.id + ' .cpi-pagemore').css('cursor','pointer');
		}
	}
};

cpi.checkvals = function(applet) {
	cpi.me = applet;
	cpi.me.currentpage = Math.round(parseInt(cpiJQ(cpi.me.id + ' .cpi-canvas').css('left'),10) * -1 / cpi.me.width) + 1;
	if (parseInt(cpiJQ(cpi.me.id + ' .cpi-canvas').css('left'),10) > 0) {
		cpiJQ(cpi.me.id + ' .cpi-canvas').css('left',0);
		cpi.me.currentpage = 1;
	}
	if (parseInt(cpiJQ(cpi.me.id + ' .cpi-canvas').css('left'),10) < ((cpi.me.lastpage - 1) * cpi.me.width * -1)) {
		cpiJQ(cpi.me.id + ' .cpi-canvas').css('left',((cpi.me.lastpage - 1) * cpi.me.width * -1));
		cpi.me.currentpage = cpi.me.lastpage;
	}
	cpi.setbuttons(cpi.me);
};

cpi.load = function() {
	cpi.load.getScript();
	cpi.load.tryReady(0);
};

cpi.doseeall = function(applet) {
	cpi.me = applet;
  var linky = cpi.me.seeallurl;

  if (cpi.me.affiliate != '')
    linky = linky + '&aid=' + cpi.me.tracking;
  
	//window.location.href = linky;
  cpi.redirect(linky);
};

function loadit(data) {
  
	cpiJQ('#log').append(cpi.me.id + '<br/>');

	cpi.me.pagesloaded++;

	cpi.me.maxresults = parseInt(data.maxresults,10);
	var cpi_resultcount = parseInt(data.resultcount,10);
	var cpi_firstresult = parseInt(data.firstresult,10);
	cpi.me.seeallurl = data.seeallurl;
	cpi.me.lastpage = (cpi.me.maxresults % (cpi.me.rowcount * cpi.me.colcount) > 0) ? Math.ceil(cpi.me.maxresults / (cpi.me.rowcount * cpi.me.colcount)) : Math.floor(cpi.me.maxresults / (cpi.me.rowcount * cpi.me.colcount));
	cpi.setbuttons(cpi.me);
  
	for(cpi_row=0;cpi_row<cpi.me.rowcount;cpi_row++) {
		for(cpi_col=0;cpi_col<cpi.me.colcount;cpi_col++) {
			cpi.me.counter++;
			cpi.me.pageproductno++;

			if (cpi.me.counter <= cpi.me.maxresults) {

				cpi.me.currentrow = cpi_row + 1;

				var product = data.product[cpi.me.counter - 1],
					cpi_caption = product.caption,
					cpi_image = product.imageurl,
					cpi_price = product.price,
					cpi_productid = product.productid,
					cpi_linkurl = product.linkurl;

        if (cpi.me.affiliate != '') 
          cpi_linkurl = cpi_linkurl + '&aid=' + cpi.me.tracking;

				if (cpi.me.issingle && cpi.me.issquare) {
					cpiJQ(cpi.me.id + ' .cpi-canvas').append('<div linkurl="' + cpi_linkurl + '" productid="' + cpi_productid + '" class="cpi-cell-' + cpi.me.counter + ' cpi-cell"><div class="cpi-thumb-' + cpi.me.counter + ' cpi-thumb"></div><div class="cpi-captionback-' + cpi.me.counter + ' cpi-captionback"></div><div class="cpi-caption-' + cpi.me.counter + ' cpi-caption"></div></div>');
					cpiJQ(cpi.me.id + ' .cpi-cell-' + cpi.me.counter).css('top', Math.floor(cpi.me.thumbsize * -0.01));
					cpiJQ(cpi.me.id + ' .cpi-cell-' + cpi.me.counter).css('left',(cpi.me.colspacing * -0.5) + 18 + (cpi.me.width * (cpi.me.pagesloaded - 1)));
				} else {
					cpiJQ(cpi.me.id + ' .cpi-canvas').append('<div linkurl="' + cpi_linkurl + '" productid="' + cpi_productid + '" class="cpi-cell-' + cpi.me.counter + ' cpi-cell"><div class="cpi-thumb-' + cpi.me.counter + ' cpi-thumb"></div><div class="cpi-caption-' + cpi.me.counter + ' cpi-caption"></div></div>');
					cpiJQ(cpi.me.id + ' .cpi-cell-' + cpi.me.counter).css('top', ((cpi_row * cpi.me.cellheight) + cpi.me.toppad) + 'px');
					cpiJQ(cpi.me.id + ' .cpi-cell-' + cpi.me.counter).css('left', ((cpi_col * cpi.me.cellwidth) + cpi.me.leftpad + (cpi.me.width * (cpi.me.pagesloaded - 1))) + 'px');
				}

				cpiJQ(cpi.me.id + ' .cpi-cell-' + cpi.me.counter).css('height',cpi.me.cellheight);
				cpiJQ(cpi.me.id + ' .cpi-cell-' + cpi.me.counter).css('width',cpi.me.cellwidth);
				cpiJQ(cpi.me.id + ' .cpi-thumb-' + cpi.me.counter).css('margin-left',cpi.me.colspacing/2);
				cpiJQ(cpi.me.id + ' .cpi-thumb-' + cpi.me.counter).css('height',cpi.me.thumbsize);
				cpiJQ(cpi.me.id + ' .cpi-thumb-' + cpi.me.counter).css('width', cpi.me.thumbsize);
				cpiJQ(cpi.me.id + ' .cpi-caption-' + cpi.me.counter).css('margin-left',cpi.me.colspacing/2);
				cpiJQ(cpi.me.id + ' .cpi-caption-' + cpi.me.counter).css('height',cpi.captionheight);
				cpiJQ(cpi.me.id + ' .cpi-caption-' + cpi.me.counter).css('width', cpi.me.thumbsize);
				cpiJQ(cpi.me.id + ' .cpi-captionback-' + cpi.me.counter).css('margin-left',cpi.me.colspacing/2);
				cpiJQ(cpi.me.id + ' .cpi-captionback-' + cpi.me.counter).css('height',cpi.captionheight);
				cpiJQ(cpi.me.id + ' .cpi-captionback-' + cpi.me.counter).css('width', cpi.me.thumbsize);

				var cpi_imageurl = cpi_image.replace("150x150",cpi.me.thumbsize + 'x' + cpi.me.thumbsize);

				if (cpi.me.issingle && cpi.me.issquare) {
					cpiJQ(cpi.me.id + ' .cpi-caption-' + cpi.me.counter).html('<div class="cpi-captionname">' + cpi_caption + ' </div><div class="cpi-captionprice">' + cpi_price + '</div>');
					cpiJQ(cpi.me.id + ' .cpi-caption-' + cpi.me.counter).css('position','absolute');
					cpiJQ(cpi.me.id + ' .cpi-caption-' + cpi.me.counter).css('bottom',0);
					cpiJQ(cpi.me.id + ' .cpi-caption-' + cpi.me.counter).css('left',15);
					cpiJQ(cpi.me.id + ' .cpi-caption-' + cpi.me.counter).css('width',cpi.me.cellwidth - 30);
					cpiJQ(cpi.me.id + ' .cpi-caption-' + cpi.me.counter).css('height',cpi.singlecaptionheight);
					cpiJQ(cpi.me.id + ' .cpi-caption-' + cpi.me.counter).css('font-weight','bold');
					cpiJQ(cpi.me.id + ' .cpi-captionback-' + cpi.me.counter).css('position','absolute');
					cpiJQ(cpi.me.id + ' .cpi-captionback-' + cpi.me.counter).css('bottom',0);
					cpiJQ(cpi.me.id + ' .cpi-captionback-' + cpi.me.counter).css('left',0);
					cpiJQ(cpi.me.id + ' .cpi-captionback-' + cpi.me.counter).css('height',cpi.singlecaptionheight);
				} else {
					cpiJQ(cpi.me.id + ' .cpi-caption-' + cpi.me.counter).html('<div class="cpi-captionname">' + cpi_caption + ' </div><div class="cpi-captionprice">' + cpi_price + '</div>');

				}
				cpiJQ(cpi.me.id + ' .cpi-thumb-' + cpi.me.counter).html('<img class="cpi-image" cpurl="http://www.cafepress.com/" productid="' + cpi_productid + '" src="' + cpi_imageurl + '" height="' + cpi.me.thumbsize + '" width="' + cpi.me.thumbsize + '"/>');
			}
		}
	}

	if (cpi.me.height > 600) {
		cpiJQ(cpi.me.id + ' .cpi-canvas').append('<div class="cpi-pagelinks cpi-pagelinks-' + cpi.me.pageno + '"></div>');
		cpiJQ(cpi.me.id + ' .cpi-pagelinks-' + cpi.me.pageno).css('width',cpi.me.width - 80);
		cpiJQ(cpi.me.id + ' .cpi-pagelinks-' + cpi.me.pageno).css('left',40 + ((cpi.me.pageno - 1) * cpi.me.width));
		cpiJQ(cpi.me.id + ' .cpi-pagelinks-' + cpi.me.pageno).css('top',cpi.me.currentrow * cpi.me.cellheight + cpi.me.toppad);
		cpiJQ(cpi.me.id + ' .cpi-pagelinks-' + cpi.me.pageno).append('<span class="cpi-linkless cpi-linkless-' + cpi.me.pageno + '" appletid="' + cpi.me.id + '">&lt; previous</span>');
		cpiJQ(cpi.me.id + ' .cpi-pagelinks-' + cpi.me.pageno).append(' | ');
		cpiJQ(cpi.me.id + ' .cpi-pagelinks-' + cpi.me.pageno).append('<span class="cpi-linkmore cpi-linkmore-' + cpi.me.pageno + '" appletid="' + cpi.me.id + '">next &gt;</span>');
		if (cpi.me.currentpage > 1) {
			cpiJQ(cpi.me.id + ' .cpi-linkless-' + cpi.me.pageno).css('color','#3366CC');
			cpiJQ(cpi.me.id + ' .cpi-linkless-' + cpi.me.pageno).css('cursor','pointer');
		}
		if (cpi.me.currentpage < cpi.me.lastpage) {
			cpiJQ(cpi.me.id + ' .cpi-linkmore-' + cpi.me.pageno).css('color','#3366CC');
			cpiJQ(cpi.me.id + ' .cpi-linkmore-' + cpi.me.pageno).css('cursor','pointer');
		}
	}

	if (cpi.me.counter < (cpi_resultcount + (cpi_firstresult - 1))) {
		cpi.me.datastore = data;
	} else {
		cpi.me.datastore = null;
	}

	cpi.addpages();

}


cpi.addpages = function() {
	if (cpi.appletqueue.length === 0) { return; }

	cpi.me = cpi.applets[cpi.appletqueue.shift()];

	cpi.me.pageno++;
	cpi.me.pageproductno = -1;

	var source = 'tag:cats',
		type = '',
		sourcecode,
		size = parseInt(cpi.me.width, 10) + parseInt(cpi.me.height, 10),
		rpp = '&resultsPerPage=',
		tracking = '&tracking=' + cpi.me.tracking;

	/* hardcode size as 25, for cacheing */
	// if(size == 800){
	// 	rpp += "15";
	// } else if(size > 1500){
	// 	rpp += "25";
	// } else {
	// 	rpp += "10";
	// }
	rpp += "25";
	
	// trim extraneous data from source
	if ((cpiJQ(cpi.me.id).attr('source') !== undefined) && (cpiJQ(cpi.me.id).attr('source') !== '')) {
		sourcecode = cpiJQ(cpi.me.id).attr('source');
		if(sourcecode.indexOf('shop:') === 0 && cpiJQ(cpi.me.id).attr('affiliate') !== ''){
			source = sourcecode.replace('shop:','');
			type = '?type=affiliateshop';
		} else if(sourcecode.indexOf('shop:') === 0){
			source = sourcecode.replace('shop:','');
			type = '?type=shop';
		} else if(sourcecode.indexOf('tag:') === 0){
			source = sourcecode.replace('tag:','');
			type = '?type=tag';
		}
	}

	if ((cpi.me.datastore !== undefined) && (cpi.me.datastore !== null)) {
		loadit(cpi.me.datastore);
	} else {
		cpiJQ.ajax({
			url: cpi.webstore + '/search/show/' + source + type + rpp + tracking,
			dataType: 'jsonp',
			contentType: 'application/json',
			jsonpCallback: 'loadit'
		});
	}
};

// dynamically load any javascript file.
cpi.load.getScript = function() {
	if(typeof jQuery !== "function" || parseInt(jQuery.fn.jquery.split('.')[1]) < 4){
		var script = document.createElement('script');
		script.setAttribute("type","text/javascript");
		script.setAttribute("src", cpi.cpcache + '/js/jquery/jquery-1.4.min.js');
		if (typeof script !== "undefined") { document.getElementsByTagName("head")[0].appendChild(script); }
	}

	var css = document.createElement('link');
	css.setAttribute("type","text/css");
	css.setAttribute("rel", 'stylesheet');
	css.setAttribute("href", cpi.cpcache + '/marketplace/widgets/stylesheets/widget.css');
	css.setAttribute("media", 'screen');
	if (typeof css!="undefined") { document.getElementsByTagName("head")[0].appendChild(css); }
};

cpi.load.tryReady = function(time_elapsed) {
	if (typeof jQuery == "undefined" || parseInt(jQuery.fn.jquery.split('.')[1]) < 4) {
		if (time_elapsed <= 10000) {
			setTimeout("cpi.load.tryReady(" + (time_elapsed + 200) + ")", 200);
		}
	} else {
		cpiJQ = jQuery;
		cpi.queue();
	}
};
cpi.load();
