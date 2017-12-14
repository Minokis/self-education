import React from 'react'
import PieStatisticSettings from './../components/PieStatisticSettings';



export default class PieStatisticContainer extends React.Component {
  constructor(props) {
    super(props);
    const showOptions = ['All tasks', 'Tasks in progress', 'In progress/Failed'];
    const plotOptions = ['Amounts', 'Weights'];
    this.state = {
      plotBy: plotOptions[0],
      showInPieChart: showOptions[0],
      pieChartTags: [
  {tag: 'work', completedWeight: 30, failedWeight: 40, weight: 70, completedAmount: 3, failedAmount: 4, amount: 7},
  {tag: 'study', completedWeight: 30, failedWeight: 40, weight: 70, completedAmount: 3, failedAmount: 4, amount: 7},
  {tag: 'sport', completedWeight: 30, failedWeight: 40, weight: 70, completedAmount: 3, failedAmount: 4, amount: 7},
  {tag: 'social', completedWeight: 30, failedWeight: 40, weight: 70, completedAmount: 3, failedAmount: 4, amount: 7},
  {tag: 'other', completedWeight: 30, failedWeight: 40, weight: 70, completedAmount: 3, failedAmount: 4, amount: 7}],

    };

    this.handlePlotChange = this.handlePlotChange.bind(this);
    this.handleShowChange = this.handleShowChange.bind(this);
    this.toggleCheckbox = this.toggleCheckbox.bind(this);
    this.handleClickPlotChart = this.handleClickPlotChart.bind(this);
  }

  componentDidMount = () => {
    let tagsToShow = new Set();
    this.setState({
      tagsToShow: tagsToShow
    });
}

  handlePlotChange(event) {
    this.setState({
      plotBy: event.target.value
    });
  }

  handleShowChange(event) {
    this.setState({
      showInPieChart: event.target.value
    });
  }

   toggleCheckbox (event) {
     let tag = event.target.name;
    if (this.state.tagsToShow.has(tag)) {
      this.state.tagsToShow.delete(tag);
    } else {
      this.state.tagsToShow.add(tag);
    }
    console.log(this.state.tagsToShow);
  }

// заглушка
  handleClickPlotChart = event => {
    event.preventDefault();
    let chartData = [];
    for (let item of this.state.pieChartTags) {
      if (this.state.tagsToShow.has(item.tag)) {
        console.log(item.tag);
        let pie = {};
        pie.name = item.tag;
        let end = this.state.plotBy.length - 1;
        let key = this.state.plotBy.substring(0, end);
        // TODO
        if (this.state.showInPieChart === 'All tasks') {
          let tagsKey = key.toLowerCase();
          console.log("All tasks selected");
        }
        else if (this.state.showInPieChart === 'Tasks in progress') {
          console.log("Tasks in progress selected");
          //let tagsKey =
        }
        else if (this.state.showInPieChart === 'In progress/Failed') {
          console.log("Complex graph is selected");
          //let tagsKey =
        }
        else {
          alert("Error processing settings: I don't understand options!");
          //let tagsKey =
        }
        //pie.value = item[tagsKey];
        chartData.push(pie);
       }

    }
    console.log(chartData);
  }

  render() {
    return(
      <PieStatisticSettings
        {...this.state}
        handlePlotChange={this.handlePlotChange}
        handleShowChange={this.handleShowChange}
        toggleCheckbox={this.toggleCheckbox}
        handleClickPlotChart={this.handleClickPlotChart}
      />
    );
  }

}
