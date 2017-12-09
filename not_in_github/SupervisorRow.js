import React from 'react'
export default class SupervisorRow extends React.Component {
	render() {
		const supervisor = this.props.supervisor;
		return(
			<tr>
        		<td>{supervisor.userId}</td>
        		<td>
        			<button type="button" class="btn" >Удалить</button>
        		</td>
      		</tr>
			);
	}
}
