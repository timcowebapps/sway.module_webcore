"use strict";

export class AbstractModel {
	public _wasm_model: any = null;

	constructor(context: any) {
		this._wasm_model = new context.module.AbstractModel();
	}
};
