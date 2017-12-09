import React from 'react'
export default class AddSupervisorForm extends React.Component {
	render() {
		return (
		<div class="col-8">
			<label id="superviserInput">
				Вставь ключ своего друга, чтобы он мог наблюдать за твоим прогрессом!
			</label>

			<div class="input-group">
	      		<input type="text" class="form-control" id="superviserInput" placeholder="############"/>
	     	 	<span class="input-group-btn">
	        		<button class="btn btn-dark" type="submit">Добавить друга!</button>
	      		</span>
	    	</div>
		</div>
		);
	}
}
