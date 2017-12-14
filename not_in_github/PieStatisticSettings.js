import React from 'react'

export default class PieStatisticForm extends React.Component {

render() {

  const tagrows = [];
   this.props.pieChartTags.forEach((pieceOfPie) => {
       tagrows.push(
         <div className="col-12" key={pieceOfPie.tag}>
			   	<label><input name={pieceOfPie.tag} type="checkbox" onChange={(event) => this.props.toggleCheckbox(event)}/> {pieceOfPie.tag} </label>
			   </div>
       );
   });

  return(
    <div className="container" style={{marginTop: "20px"}}>
      <div className="row justify-content-center">

        <div className="col-9">

          <form>
            <div className="form-group row">
              <label className="col-2">Plot:</label>
              <label className="col-3">
                <input type="radio" name="type" value="Amounts"
                checked={this.props.plotBy === 'Amounts'}
                onChange={this.props.handlePlotChange}/> Amounts
              </label>
              <label className="col-3">
                <input type="radio" name="type" value="Weights"
                checked={this.props.plotBy === 'Weights'}
                onChange={this.props.handlePlotChange}/> Weights
              </label>
            </div>
          </form>

          <form>
            <div className="form-group row">
              <label className="col-2">Show:</label>
              <label className="col-3">
                <input type="radio" name="type" value="All tasks"
                checked={this.props.showInPieChart === "All tasks"}
                onChange={this.props.handleShowChange}/> All tasks
              </label>
              <label className="col-3">
                <input type="radio" name="type" value="Tasks in progress"
                checked={this.props.showInPieChart === "Tasks in progress"}
                onChange={this.props.handleShowChange}/> Tasks in progress
              </label>
              <label className="col-4">
                <input type="radio" name="type" value="In progress/Failed"
                checked={this.props.showInPieChart === "In progress/Failed"}
                onChange={this.props.handleShowChange}/> In progress/Failed
              </label>
            </div>
						<button className="btn btn-default btn-block" type="submit"  onClick={this.props.handleClickPlotChart}>Plot chart</button>
          </form>
        </div>

        <div className="col-3">
					<label>Tick tags to show:</label>
					<form>
						{tagrows}

					</form>
				</div>
			</div>
		</div>
  );
}

}
