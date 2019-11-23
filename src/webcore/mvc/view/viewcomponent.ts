"use strict";

import * as _ from "underscore";
import { IViewComponentOptions } from "./viewcomponentoptions";

export interface IView {
	[name: string]: any;
	_wasm_viewcomponent: any;
};

export class ViewComponent implements IView {
	public _wasm_context: any = null;
	public _wasm_viewcomponent: any = null;

	/**
	 * Конструктор представления.
	 * 
	 * @method constructor
	 * @param {any} context Контекст.
	 * @param {IViewOptions} options Свойства представления.
	 */
	constructor(context: any, options: IViewComponentOptions) {
		this._wasm_viewcomponent = function (self: any) {
			var viewComponentOptions = { tagname: "div", classname: "" };
			var ViewComponent = context.module.ViewComponent.extend("ViewComponent", {
				__construct: function(name, options) {
					this.__parent.__construct.call(this, name, options);
				},
				__destruct: function() {
					this.__parent.__destruct.call(this);
				},
				prerepaint: _.bind(self.prerepaint, self)
			});

			return new ViewComponent(options.id, _.defaults(options, viewComponentOptions));
		}(this) as any;

		this._wasm_context = context;
	}

	public initialize(): void {
		// Empty
	}

	public prerepaint(): void {
		// Empty
	}

	public setRegion(region: any): void {
		this._wasm_viewcomponent.setRegion(region);
	}

	public getModel(): any {
		return this._wasm_viewcomponent.getModel();
	}

	public setModel(model: any): void {
		this._wasm_viewcomponent.setModel(model._wasm_model);
	}

	public addChild(view: IView): void {
		this._wasm_viewcomponent.addChild(view._wasm_viewcomponent);
	}

	public removeChild(view: IView): void {
		this._wasm_viewcomponent.removeChild(view._wasm_viewcomponent);
	}

	public getChildCount(): number {
		return this._wasm_viewcomponent.getChildCount();
	}

	public addChildView(view: IView): void {
		this._wasm_viewcomponent.addChildView(view._wasm_viewcomponent);
	}

	public removeChildView(view: IView): void {
		if (_.isNull(view._wasm_viewcomponent))
			return;

		this._wasm_viewcomponent.removeChildView(view._wasm_viewcomponent);
		delete view._wasm_viewcomponent;
	}

	public addEvent(targetId: string, type: any, callback: any): void {
		this._wasm_viewcomponent.addEvent(targetId, type, callback);
	}
};
