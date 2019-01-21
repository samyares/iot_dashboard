var randomScalingFactor = function(){ return Math.round(Math.random()*100)};
	
	var lineChartData = {
		labels : ["before","20sec ago","15sec ago","10sec ago","5sec ago","now"],
		datasets : [
			{
				label: "My First dataset",
				fillColor : "rgba(220,220,220,0.3)",
				strokeColor : "rgba(220,220,220,1)",
				pointColor : "rgba(220,220,220,1)",
				pointStrokeColor : "#fff",
				pointHighlightFill : "#fff",
				pointHighlightStroke : "rgba(220,220,220,1)",
				data : [100,randomScalingFactor(),randomScalingFactor(),randomScalingFactor(),randomScalingFactor(),randomScalingFactor()]
			}
		]

	}