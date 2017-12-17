import React from 'react'
import PieStatisticSettings from './../components/PieStatisticSettings';
import Graphics from './../components/Graphics';



export default class PieStatisticContainer extends React.Component {
  constructor(props) {
    super(props);
    const showOptions = ['All tasks', 'Tasks in progress', 'In progress/Failed'];
    const plotOptions = ['Amounts', 'Weights'];
    this.state = {
      plotBy: plotOptions[0],
      showInPieChart: showOptions[0],
      pieChartTags: [
  {tag: 'work', completedWeight: 180, failedWeight: 10, weight: 200, completedAmount: 18, failedAmount: 1, amount: 20},
  {tag: 'study', completedWeight: 100, failedWeight: 40, weight: 300, completedAmount: 10, failedAmount: 4, amount: 30},
  {tag: 'sport', completedWeight: 30, failedWeight: 40, weight: 120, completedAmount: 3, failedAmount: 4, amount: 12},
  {tag: 'social', completedWeight: 100, failedWeight: 0, weight: 150, completedAmount: 2, failedAmount: 0, amount: 3},
  {tag: 'other', completedWeight: 30, failedWeight: 20, weight: 80, completedAmount: 3, failedAmount: 2, amount: 8}],
    dataForGraphics: []
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

   toggleCheckbox(event) {
     let tag = event.target.name;
    if (this.state.tagsToShow.has(tag)) {
      this.state.tagsToShow.delete(tag);
    } else {
      this.state.tagsToShow.add(tag);
    }
  }

  createDataForGraphics() {
    let chartData = [];
    for (let item of this.state.pieChartTags) {
      if (this.state.tagsToShow.has(item.tag)) {
        let key = this.state.plotBy.substring(0, this.state.plotBy.length - 1);
        // TODO
        if (this.state.showInPieChart === 'All tasks') {
          let pie = {};
          pie.name = item.tag;
          pie.value = item[key.toLowerCase()];
          chartData.push(pie);
        }
        else if (this.state.showInPieChart === 'Tasks in progress') {
          let pie = {};
          pie.name = item.tag;
          pie.value = item[key.toLowerCase()] - item["completed" + key] - item["failed" + key];
          chartData.push(pie);
        }
        else if (this.state.showInPieChart === 'In progress/Failed') {
          let pieInProgress = {};
          let pieFailed = {};
          pieInProgress.name = item.tag + " in progress";
          pieFailed.name = item.tag + " failed";
          pieInProgress.value = item[key.toLowerCase()] - item["completed" + key] - item["failed" + key];
          pieFailed.value = item["failed" + key];
          chartData.push(pieInProgress);
          chartData.push(pieFailed);
        }
        else {
          alert("Error processing settings: I don't understand options!");
        }
       }
    }
    return chartData;
  }

  handleClickPlotChart (event) {
    event.preventDefault();
    let dataForGraphics = this.createDataForGraphics();
    this.setState({dataForGraphics: dataForGraphics});
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
