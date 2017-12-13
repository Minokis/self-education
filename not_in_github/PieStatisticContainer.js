import React from 'react'
import PieStatisticSettings from './../components/PieStatisticSettings';

const showOptions = ['All tasks', 'Tasks in progress', 'In progress/Failed'];
const plotOptions = ['Amounts', 'Weights'];

export default class PieStatisticContainer extends React.Component {
  constructor(props) {
    super(props);
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
    this.handleSettingsSubmit = this.handleSettingsSubmit.bind(this);
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
  handleSettingsSubmit = event => {
    event.preventDefault();
    console.log(this.state);
    for (let item of this.state.tagsToShow) console.log(item);
  }

  render() {
    return(
      <PieStatisticSettings
        {...this.state}
        handlePlotChange={this.handlePlotChange}
        handleShowChange={this.handleShowChange}
        toggleCheckbox={this.toggleCheckbox}
        handleSettingsSubmit={this.handleSettingsSubmit}
      />
    );
  }

}
